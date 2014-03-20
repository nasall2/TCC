#include <stdlib.h>
#include <stdio.h>

#include "packet_headers.h"
#include "ISO13818_definitions.h"

void test();

typedef struct {
	char a;
	char b;
	char c;
	char d;
} char_structure;

typedef struct {
	uint a;
	uint b;
	uint c;
	uint d;
} uint_structure;

void test(){

	int i;
		
	FILE * output_TS_ptr;
	output_TS_ptr= fopen("output_TS.TS","w");

	char_structure struc;
	char_structure * struc_ptr;
	char* struc_a_ptr;
	char* struc_b_ptr;

	uint_structure struc_u;
	uint_structure* struc_u_ptr;
	uint* struc_u_a_ptr;
	uint* struc_u_b_ptr;

	uint* pointer;

	pointer = &struc_u;

	struc_ptr = &struc;
	struc_a_ptr = &(struc.a);
	struc_b_ptr = &(struc.b);

	struc_u_ptr = &struc_u;
	struc_u_a_ptr = &(struc_u.a);
	struc_u_b_ptr = &(struc_u.b);

	struc_ptr->a = 0x00;
	struc_ptr->b = 0x11;
	struc_ptr->c = 0x22;
	struc_ptr->d = 0x33;

	struc_u_ptr->a = 0x33221100;
	struc_u_ptr->b = 0x77665544;
	struc_u_ptr->c = 0xbbaa9988;
	struc_u_ptr->d = 0xffeeddcc;

//	printf("%X \n", struc_ptr->a);
//	printf("%X \n", struc_ptr);
//	printf("%X \n", struc_a_ptr++);
//	printf("%X \n", struc_b_ptr);
//
	printf("%X \n", struc_u_ptr->a);
	printf("%X \n", struc_u_ptr);
	printf("%X \n", struc_u_a_ptr);
	printf("%X \n", struc_u_b_ptr);
	printf("%X \n", (long) struc_u_b_ptr - (long) struc_u_a_ptr);

//    printf("%hhX \n", (char) (*pointer));
//    putc((char) (*pointer), output_TS_ptr);

	printf("\n");

	printf("%X \n", sizeof(uint));
    for(i=0;i<TS_PACKET_HEADER_LENGTH;i++) {
//	printf("%d, %d:\t%X \n", i, (pointer + i*4), *(pointer + i*4));
	printf("%X \n", * (uint_structure *) ( struc_u_ptr + i*sizeof(uint)));
    }
}
