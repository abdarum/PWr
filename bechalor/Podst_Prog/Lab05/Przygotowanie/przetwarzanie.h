/* Modul funkcji przetwarzania obrazow */

/*
 *  x - wymiar obrazu (szerokosc)
 *  y - wymiar obrazu (wysokosc)
 *  obraz_wej[][] - tablica ktora ma byc poddana przetwarzaniu
 *  obraz_wyj[][] - tablica ktora powstaje po przetworzeniu tablicy "obraz_wej[][]"
 *  biel  - zmienna sluzy do zmiany poiomow jest to wartosc podawana w liczbach calkowitych odpowiadajocych procentom - dla 80% jest to liczba 80
 *  czern - podobnie jak w przypadku biel
 *  skala - skala szarosci obrazu
 */

#include "obraz_wlasciwosci.h"

void negatyw(int x, int y,int obraz_wej[][MAX], int obraz_wyj[][MAX]);
void konturowanie(int x, int y,int obraz_wej[][MAX], int obraz_wyj[][MAX]);
void zmiana_poziomow(int x,int y,int obraz_wej[][MAX],int obraz_wyj[][MAX],int biel,int czern,int skala);
void rozciaganie_histogramu(int x,int y,int obraz_wej[][MAX],int obraz_wyj[][MAX],int skala);
