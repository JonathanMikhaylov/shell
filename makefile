GCC = gcc
all: shell.o
	$(GCC) shell.o -lreadline -o shell 

shell.o: shell.c shell.h
	$(GCC) -c shell.c
clean:
	rm *.o
	rm *~

run: all
	./shell