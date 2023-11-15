CC = gcc
CFLAGS = -Wall -Wextra 

A4Program: main.o building.o ghost.o additional.o room.o
	$(CC) -o A4Program main.o building.o ghost.o additional.o room.o


main.o: main.c  defs.h
	$(CC) $(CFLAGS) -c main.c building.c ghost.c additional.c room.c



clean:
	rm -f *.o A4Program
