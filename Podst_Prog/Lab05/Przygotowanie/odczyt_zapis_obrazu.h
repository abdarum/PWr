#include "obraz_wlasciwosci.h"

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci);
void wyswietl(char *n_pliku);
int zapisz(FILE *plik_wy, int wymx, int wymy, int szarosci, int obraz_pgm[][MAX]);
void kopiuj(int x, int y,int obraz_wej[][MAX], int obraz_wyj[][MAX]);
