#include <stdlib.h>
#include <stdio.h>

#include "packet_headers.h"
#include "ISO13818_definitions.h"

void main(){

	TS_packet_header header;
	TS_packet_header * header_ptr;

	FILE * video_ES_ptr;
	FILE * audio_ES_ptr;
	FILE * output_TS_ptr;
	int i;

	int teste;
	int * teste_ptr;

	header_ptr = &header;

	header.sync_byte = 0xff;			// xxxx xxxx
	header.transport_error_indicator = 0x1; 	// x
	header.payload_unit_start_indicator = 0x1; 	// x
	header.transport_priority = 0x1; 		// x
	header.PID = 0x1fff; 				// xxxx xxxx xxxx x
	header.transport_scrambling_control = 0x3; 	// xx
	header.adaptation_field_control = 0x3;		// xx
	header.continuity_counter = 0xf;		// xxxx


//	printf("HEADER sync byte:\n%x\n",header.sync_byte);
//	printf("HEADER PID:\n%x\n",header.PID);
//	printf("HEADER adaptation_field_control:\n%x\n",header.adaptation_field_control);
//	printf("HEADER continuity counter:\n%x\n",header.continuity_counter);

	video_ES_ptr = fopen("video_ES.ES","w");
	audio_ES_ptr = fopen("audio_ES.ES","w");
	output_TS_ptr= fopen("output_TS.TS","w");

//	for(i = 0; i<TS_PACKET_HEADER_LENGTH; i++) {
//		putc(0x00,video_ES_ptr);
//		printf("%hhX \t", *(header_ptr));
//	}

	printf("\n");

//	for(i = 0; i<10; i++) {
//		putc(0xff,audio_ES_ptr);
//	}

	printf("%X \n", *header_ptr);
	printf("%hhX \n", *header_ptr);
//	fprintf(output_TS_ptr, "%X \n", *header_ptr);
	putc(*header_ptr,output_TS_ptr);
	printf("\n");
}

