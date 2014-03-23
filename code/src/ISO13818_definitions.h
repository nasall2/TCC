/*
	This file defines for the code the mandatory aspects of ISO13818 standard.


			Lucas
*/

#define SYNC_BYTE 0x47


#define TS_PACKET_HEADER_LENGTH	4	//In bytes
#define TS_PACKET_LENGTH	188	//In bytes
#define TS_PACKET_PAYLOAD_LENGTH (TS_PACKET_LENGTH-TS_PACKET_HEADER_LENGTH)
#define MAX_PACKETS_TO_WRITE 10000
