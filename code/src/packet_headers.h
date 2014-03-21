#include <stdlib.h>
#include <stdio.h>

#include "ISO13818_definitions.h"

//Variable type definitions

#define uint unsigned int
#define DEBUG(var) printf("DEBUG:" #var ": %d\n", var)

typedef struct {

    uint	sync_byte			: 8;
    uint	transport_error_indicator	: 1;
    uint	payload_unit_start_indicator	: 1;
    uint	transport_priority		: 1;
    uint	PID				:13;
    uint	transport_scrambling_control	: 2;
    uint	adaptation_field_control	: 2;
    uint	continuity_counter		: 4;
} TS_packet_header;

typedef struct {

    TS_packet_header	header;
    char		payload[TS_PACKET_PAYLOAD_LENGTH];

} TS_packet;

    


//typedef struct {
//} PES_packet_header
