CFLAGS:=-I../include
INCLUDE_DIR:=../include
SRC_DIR:=../src
RUN_DIR:=/run
COMPILER=gcc
USERNAME:=$(shell bash -c 'whoami')
HOMEDIR:=/home/$(USERNAME)
CWD:=$(shell pwd)

.PHONY: test

test:
	@clear
	@echo $(USERNAME)
	@echo $(HOMEDIR)
	@echo $(CWD)

Glthreads:
	gcc -g -c -I/home/coach/GitHub/DSA/C/include /home/coach/GitHub/DSA/C/src/glthread2.c -o /home/coach/GitHub/DSA/C/src/glthread2.o
	gcc -g -c -I/home/coach/GitHub/DSA/C/include test.c -o test.o
	gcc -g test.o /home/coach/GitHub/DSA/C/src/glthread2.o -o test.out

GlthreadsClean:
	rm -f /home/coach/GitHub/DSA/C/src/glthread.o
	rm -f /home/coach/GitHub/DSA/C/src/glthread2.o
	rm -f test.out
	rm -f test.o
	rm -f test
	rm -f Glthreads


ArrayADT:
	$(COMPILER) ArrayADT.c ../src/ArrayADT.c -o ArrayADT $(CFLAGS)

ArrayADT-clean:
	rm -f ArrayADT

#=================
#GLThreads targets
#=================
glthreads.o:
	$(COMPILER) -I$(INCLUDE_DIR) $(SRC_DIR)/glthread.c -o $(SRC_DIR)/glthread.o

glthreadsClean:
	rm -f /home/coach/GitHub/DSA/C/src/glthread.o

#=================
#QuickSort targets
#=================
CleanQuickSort:
	rm QuickSort

QuickSort: QuickSort.c
	$(COMPILER) QuickSort.c ../src/ArrayADT.c -o QuickSort $(CFLAGS)
	./QuickSort