#include <stdlib.h>
#include <stdio.h>

#include "packet_headers.h"
#include "ISO13818_definitions.h"

void main(int argc, char* argv[]){

    int i;
    int bytes;

    if ( argc < 2 ) {
	printf("usage: %s number of bytes \n", argv[0]);
	return;
	}

    bytes = strtol(argv[1], NULL, 0);

    FILE * output_ptr;
    output_ptr= fopen("video_ES.ES","w");

    for( i=0; i<bytes; i++ ) {
	putc(i,output_ptr);
    }

    return;
}
