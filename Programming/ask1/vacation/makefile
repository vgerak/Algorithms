CC = gcc
CFLAGS = -Wall -Wextra -O2

all:		vacation
vacation:	vacation.o
	${CC} vacation.o -o vacation ${LDFLAGS}
vacation.o:	vacation.c vacation.h
	${CC} -c vacation.c -o vacation.o ${CFLAGS}

.PHONY:	clean
clean:
	rm vacation.o vacation
test:
	./vacation < testcases/input${TEST}.txt
	cat testcases/output${TEST}.txt
