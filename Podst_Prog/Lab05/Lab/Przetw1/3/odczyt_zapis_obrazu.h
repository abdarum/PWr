#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DL_LINII 1024

#ifndef STRUKTURA
#define STRUKTURA
typedef struct{
  int *red,*green,*blue;
  int *tablica;
  int wymx, wymy, szarosci;
  int rgb,bw;
}obraz_struct;
#endif


int czytaj(FILE *plik_we,obraz_struct *obraz);
int zapisz(FILE *plik_wy,obraz_struct *obraz);
void wyswietl(char *n_pliku);
