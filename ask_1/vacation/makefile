all:		vacation
vacation:	vacation.o
	gcc vacation.o -o vacations -Wall
vacation.o:	vacation.c vacation.h
	gcc -c vacation.c -o vacation.o -Wall

.PHONY:	clean
clean:
	rm vacation.o vacation
