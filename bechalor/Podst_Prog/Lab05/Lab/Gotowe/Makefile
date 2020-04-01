CC=gcc
CFLAGS=-c -Wall -pedantic -Wno-vla

all: przetwarzanie2

przetwarzanie2: main.o przetwarzanie.o odczyt_zapis_obrazu.o opcje.o
	$(CC) przetwarzanie.o odczyt_zapis_obrazu.o opcje.o main.o -o Przetwarzanie_obrazow_2

main.o: main.c
	$(CC) $(CFLAGS) main.c

przetwarzanie.o: przetwarzanie.c
	$(CC) $(CFLAGS)	przetwarzanie.c

odczyt_zapis_obrazu.o: odczyt_zapis_obrazu.c
	$(CC) $(CFLAGS) odczyt_zapis_obrazu.c

opcje.o: opcje.c
	$(CC) $(CFLAGS) opcje.c

clean:
	rm -rf *.o przetwarzanie2
