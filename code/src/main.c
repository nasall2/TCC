#include <stdlib.h>
#include <stdio.h>

#include "packet_headers.h"

void main(){

	TS_packet_header header;

	printf("Hello world!\n");

	header.sync_byte = 0x00;
	header.PID = 0x0555; // 0 0000 0000 0000
	header.adaptation_field_control = 0x3;
	header.continuity_counter = 0xF;
	
	printf("HEADER sync byte:\n%x\n",header.sync_byte);
	printf("HEADER PID:\n%x\n",header.PID);
	printf("HEADER adaptation_field_control:\n%x\n",header.adaptation_field_control);
	printf("HEADER continuity counter:\n%x\n",header.continuity_counter);

}
