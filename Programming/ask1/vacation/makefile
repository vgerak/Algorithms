CC = gcc
CFLAGS = -Wall -Wextra -O3

all:		vacation
vacation:	vacation.o
	${CC} vacation.c -o vacation ${LDFLAGS}

.PHONY:	clean
clean:
	rm vacation
test:
	./vacation < testcases/input${TEST}.txt
	cat testcases/output${TEST}.txt
