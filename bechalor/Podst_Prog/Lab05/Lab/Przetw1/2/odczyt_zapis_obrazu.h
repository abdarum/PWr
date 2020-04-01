#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "struktura.h"
#define DL_LINII 1024



int czytaj(FILE *plik_we,obraz_struct *obraz);
int zapisz(FILE *plik_wy,obraz_struct *obraz);
void wyswietl(char *n_pliku);
