CFLAGS=-Wall -Wextra -Wuninitialized -O3
all:	teleport
teleport:	teleport.c
		gcc teleport.c -o teleport ${CCFLAGS}
clean:
		rm teleport
tests:
		./teleport < testcases/input${TEST}.txt
			@cat testcases/output${TEST}.txt
