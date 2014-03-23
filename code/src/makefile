
FLAGS=-c -Wall

all:	main

main:	clearmux
	rm -f mux
	gcc main.c -o mux

test:	cleartest
	gcc test.c -o test

cleartest:
	rm -f *.out test

clearmux:
	rm -f *.out mux

purgestreams:
	rm *.TS *.ES
