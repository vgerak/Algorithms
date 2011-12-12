CC = gcc
CFLAGS = -Wall -Wextra -O3

all:		books

books:		books.o
		${CC} books.o -o books ${LDFLAGS}
books.o:	books.c books.h
		${CC} -c books.c -o books.o ${CFLAGS}

.PHONY:	clean
clean:
		rm books.o books
test:
		./books < testcases/input${TEST}.txt
			cat testcases/output${TEST}.txt

