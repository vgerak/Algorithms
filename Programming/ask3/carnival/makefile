TARGET = carnival
CC = gcc
CFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	${TARGET}

${TARGET}:	${TARGET}.c
		${CC} ${TARGET}.c -o ${TARGET} ${CCFLAGS}
clean:
		rm ${TARGET}
tests:
		./${TARGET} < testcases/input${TEST}.txt
			@cat testcases/output${TEST}.txt
