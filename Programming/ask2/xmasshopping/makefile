CFLAGS=-O2
all:	xmasshopping
xmasshopping:	xmasshopping.c
		gcc xmasshopping.c -o xmasshopping ${CCFLAGS}
clean:
		rm xmasshopping
tests:
		./xmasshopping < testcases/input${TEST}.txt
			@cat testcases/output${TEST}.txt
