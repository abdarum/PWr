#ifndef ODCZYT_ZAPIS_OBRAZU
#define ODCZYT_ZAPIS_OBRAZU

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "opcje.h"
#define DL_LINII 1024


typedef struct{
  int *red,*green,*blue;
  int *tablica;
  int wymx, wymy, szarosci;
  int bw,r,g,b;
  w_rgb rgbw;
}obraz_struct;

int czytaj(FILE *plik_we,obraz_struct *obraz);
int zapisz(FILE *plik_wy,obraz_struct *obraz);
void zrob_czarno_bialy(obraz_struct *obraz);
void wyzeruj_obraz(obraz_struct *obraz);
void zwolnij_obraz(obraz_struct *obraz);
void wyswietl(char *n_pliku);


#endif
