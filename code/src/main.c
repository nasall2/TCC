#include <stdlib.h>
#include <stdio.h>

#include "packet_headers.h"

void main(){

	TS_packet_header header;
	FILE * video_ES_ptr;
	FILE * audio_ES_ptr;
	FILE * output_TS_ptr;
	int i;

	printf("Hello world!\n");

//	header.sync_byte = 0x00;
	header.PID = 0x0555; // 0 0000 0000 0000
	header.adaptation_field_control = 0x3;
	header.continuity_counter = 0xF;
	
//	printf("HEADER sync byte:\n%x\n",header.sync_byte);
//	printf("HEADER PID:\n%x\n",header.PID);
//	printf("HEADER adaptation_field_control:\n%x\n",header.adaptation_field_control);
//	printf("HEADER continuity counter:\n%x\n",header.continuity_counter);

	video_ES_ptr = fopen("video_ES.ES","w");
	audio_ES_ptr = fopen("audio_ES.ES","w");

//	for(i = 0; i<=255; i++) {
//		putc(0x00,video_ES_ptr);
		//printf("%x \t",i);
//	}

//	for(i = 0; i<=255; i++) {
//		putc(0xff,audio_ES_ptr);
		//printf("%x \t",i);
//	}

}

