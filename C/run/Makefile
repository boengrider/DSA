CFLAGS:=-I../include
CC:=gcc

Glthreads: Glthreads.c
	$(CC) Glthreads.c ../src/Glthreads.c -o Glthreads $(CFLAGS)

ArrayADT:
	$(CC) ArrayADT.c ../src/ArrayADT.c -o ArrayADT $(CFLAGS)

#=================
#QuickSort targets
#=================
CleanQuickSort:
	rm QuickSort

QuickSort: QuickSort.c
	$(CC) QuickSort.c ../src/ArrayADT.c -o QuickSort $(CFLAGS)
	./QuickSort


test: test.o
	$(CC) test.o -o test
	./test

test.o: test.c
	$(CC) -c test.c -o test.o

test.c:
	printf "#include <stdio.h>\nint main() { printf(\"Hello Make\");}" > test.c

clean:
	rm -f test.c