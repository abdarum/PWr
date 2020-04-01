CC=gcc
CFLAGS=-c -Wall -pedantic 

all: kalkulator

kalkulator: main.o funkcje_stosu.o
	$(CC) funkcje_stosu.o main.o -o Kalkulator_RPN

main.o: main.c
	$(CC) $(CFLAGS) main.c

funkcje_stosu.o: funkcje_stosu.c
	$(CC) $(CFLAGS)	funkcje_stosu.c

clean:
	rm -rf *.o kalkulator
