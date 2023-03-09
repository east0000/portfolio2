CC = gcc
CFLAGS = -g -Wall
PROGRAMS = input.o analysis.o output.o main.o main

all: $(PROGRAMS)

clean: 
	rm -f *.o *~

input.o: input.c parameter.h
	$(CC) $(CFLAGS) -c $^

analysis.o: analysis.c parameter.h
	$(CC) $(CFLAGS) -c $^

output.o: output.c parameter.h
	$(CC) $(CFLAGS) -c $^

main.o: main.c parameter.h
	$(CC) $(CFLAGS) -c $^

main: main.o input.o analysis.o output.o
	$(CC) $(CFLAGS) -o $@ $^
