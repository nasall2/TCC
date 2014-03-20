#include <stdlib.h>
#include <stdio.h>

#include "packet_headers.h"
#include "ISO13818_definitions.h"

TS_packet_header write_TS_packet_header(uint PID, uint continuity_counter) {

    if(PID>0x1FFF || continuity_counter>0xf) {
	printf("You have errors in TS packet header fields.\n");
	printf("PID and/or cont_ctr exceed expeted values.\n");
	return NULL

    header->sync_byte = SYNC_BYTE;			    // xxxx xxxx
    header->transport_error_indicator = 0b0;	    // x
    header->payload_unit_start_indicator = 0b1;	    // x
    header->transport_priority = 0b0;		    // x
    header->PID = 0x0001;			    // xxxx xxxx xxxx x
    header->transport_scrambling_control = 0b00;    // xx
    header->adaptation_field_control = 0b00;	    // xx
    header->continuity_counter = 0x1;		    // xxxx

}

void main(){

    TS_packet_header header;
    TS_packet packet;

    FILE* video_ES;
    FILE* audio_ES;
    FILE* output_TS;

    int i;

//  open streams
    video_ES = fopen("video_ES.ES","r");
    audio_ES = fopen("audio_ES.ES","r");
    output_TS = fopen("output_TS.TS","w");

//ACTION!!!

    write_TS_packet_header(&header);
    packet.header = header;

    for(i=0;i<TS_PACKET_PAYLOAD_LENGTH;i++)
	packet.payload[i] = i;

    fwrite (&packet, TS_PACKET_LENGTH, 1, output_TS);

//  close streams
    fclose(video_ES);
    fclose(audio_ES);
    fclose(output_TS);
}
