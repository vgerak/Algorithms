CFLAGS=-O3
all:	xmasshopping
xmasshopping:	xmasshopping.c
		gcc xmasshopping.c -o xmasshopping ${CFLAGS}
clean:
		rm xmasshopping
tests:
		./xmasshopping < testcases/input${TEST}.txt
			@cat testcases/output${TEST}.txt
