
CC = gcc 
all: main 
 
main: main.o calc.o calc.h 
	$(CC) main.o calc.o -o main 
 
main.o: main.c calc.h 
	$(CC) -c main.c 
 
calc.o: calc.c calc.h 
	$(CC) -c calc.c  
 
clean: 
	rm -rf *.o main
.PHONY: phony #This is a dummy phony target 
phony:
