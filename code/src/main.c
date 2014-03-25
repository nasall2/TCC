#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "packet_headers.h"
#include "ISO13818_definitions.h"

TS_packet_header write_TS_packet_header(uint PID, bool continuity_counter_reset) {

    TS_packet_header header;
    static int continuity_counter;

    if (PID>0x1FFF || continuity_counter_reset>1) {
	printf("You have errors in TS packet header fields.\n");
	printf("PID and/or cont_ctr exceed expeted values.\n");
	return;
    }
    
    if (continuity_counter_reset == true)
	continuity_counter=0;
    else
	continuity_counter++;

    header.sync_byte = SYNC_BYTE;		    // xxxx xxxx
    header.transport_error_indicator = 0b0;	    // x
    header.payload_unit_start_indicator = 0b1;	    // x
    header.transport_priority = 0b0;		    // x
    header.PID = PID;				    // xxxx xxxx xxxx x
    header.transport_scrambling_control = 0b00;	    // xx
    header.adaptation_field_control = 0b00;	    // xx
    header.continuity_counter = continuity_counter; // xxxx
    
    return header;

}

void main(){

    TS_packet packet;

    FILE* video_ES;
    FILE* audio_ES;
    FILE* output_TS;

    int packet_count, byte_number;
    int TS_packet_free_byte_counter;
    bool available_data_on_input_streams;
    char temp_byte;

//  open streams
    video_ES = fopen("video_ES.ES","r");

    if ( video_ES == NULL )
	printf("ERROR: Impossible to open input stream\n");
    else
	available_data_on_input_streams = true;

    output_TS = fopen("output_TS.TS","w");

// set startup conditions
    write_TS_packet_header(0,true); //Reset continuity counter
    byte_number = 0;
    packet_count = 0;

// ACTION!!!
    while (available_data_on_input_streams) {
    	
	packet.header = write_TS_packet_header(0x0001,false);
    
	printf("Checkpoint 1\n");
	DEBUG(byte_number);
        if (byte_number < TS_PACKET_PAYLOAD_LENGTH) {
		temp_byte = getc(video_ES);
		DEBUG(temp_byte);
	    if (available_data_on_input_streams && temp_byte != EOF) {
		packet.payload[byte_number] = temp_byte;
	    }
	    else {
		packet.payload[byte_number] = 0xFF;//stuffing bytes
	    }
        }


    	fwrite (&packet, TS_PACKET_LENGTH, 1, output_TS);
    
    	if ( feof(video_ES) ) //no more data on input file
    	    available_data_on_input_streams = false;
    
    	if (packet_count == MAX_PACKETS_TO_WRITE) //loop safety limit
    	    available_data_on_input_streams = false;
    	packet_count++;
    	DEBUG(packet_count);
    }
//  close streams
    fclose(video_ES);
    fclose(output_TS);
}
