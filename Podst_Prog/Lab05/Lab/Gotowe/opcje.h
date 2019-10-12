/********************************************************************/
/*                                                                  */
/* ALTERNATYWNA DO PRZEDSTAWIONEJ NA WYKLADZIE WERSJA OPRACOWANIA   */
/* PARAMETROW WYWOLANIA PROGRAMU UWZGLEDNIAJACA OPCJE Z PARAMETRAMI */
/* Z ODPOWIEDNIO ZAPROPONOWANYMI STRUKTURAMI DANYCH PRZEKAZUJACYMI  */
/* WCZYTANE USTAWIENIA                                              */
/*                                    COPYRIGHT (c) 2007-2013 ZPCiR */
/*                                                                  */
/* Autorzy udzielaja kazdemu prawa do kopiowania tego programu      */
/* w calosci lub czesci i wykorzystania go w dowolnym celu, pod     */
/* warunkiem zacytowania zrodla                                     */
/*                                                                  */
/********************************************************************/
#ifndef OPCJE
#define OPCJE

#include<stdio.h>
#include<string.h>
#define W_OK 0                   /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1    /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY   -2
#define B_BRAKWARTOSCI  -3
#define B_BRAKPLIKU   -4

typedef struct {
  int r,g,b,bw;
}w_rgb;

/* strukura do zapamietywania opcji podanych w wywolaniu programu */
typedef struct {
  FILE *plik_we, *plik_wy;        /* uchwyty do pliku wej. i wyj. */
  int negatyw,progowanie,progowanie_czerni,progowanie_bieli;  /* opcje */
  int zmiana_poziomow,konturowanie,rozmywanie_poziome;
  int rozciaganie_histogramu,rozmywanie_pionowe;
  int w_prog,c_prog,b_prog,poz_bieli,poz_czerni;              /* wartosci opcji */ 
  int wyswietlenie,zapisz;
  char nazwa_pliku[100];
  w_rgb rgbw;
} w_opcje;

/*******************************************************/
/* Funkcja inicjuje strukture wskazywana przez wybor   */
/* PRE:                                                */
/*      poprawnie zainicjowany argument wybor (!=NULL) */
/* POST:                                               */
/*      "wyzerowana" struktura wybor wybranych opcji   */
/*******************************************************/

void wyzeruj_opcje(w_opcje * wybor);


/************************************************************************/
/* Funkcja rozpoznaje opcje wywolania programu zapisane w tablicy argv  */
/* i zapisuje je w strukturze wybor                                     */
/* Skladnia opcji wywolania programu                                    */
/*         program  {[-i nazwa] [-m (r[g][b])|(g[r][b])|(b[r][g])|(s)   */
/* [-o nazwa] [-d] [-n] [-p liczba]  [-pc liczba] [-pb liczba]          */
/* [-z liczba liczba] [-k] [-rx] [-ry] [-h]}                            */
/* liczba musi sie zawierac w przedziale od 0 do 100                    */
/* Argumenty funkcji:                                                   */
/*         argc  -  liczba argumentow wywolania wraz z nazwa programu   */
/*         argv  -  tablica argumentow wywolania                        */
/*         wybor -  struktura z informacjami o wywolanych opcjach       */
/* PRE:                                                                 */
/*      brak                                                            */
/* POST:                                                                */
/*      funkcja otwiera odpowiednie pliki, zwraca uchwyty do nich       */
/*      w strukturze wybór, do tego ustawia na 1 pola, ktore            */
/*	poprawnie wystapily w linii wywolania programu,                 */
/*	pola opcji nie wystepujacych w wywolaniu ustawione sa na 0;     */
/*	zwraca wartosc W_OK, gdy wywolanie bylo poprawne                */
/*	lub kod bledu zdefiniowany stalymi B_* (<0)                     */
/* UWAGA:                                                               */
/*      funkcja nie sprawdza istnienia i praw dostepu do plikow         */
/*      w takich przypadkach zwracane uchwyty maja wartosc NULL         */
/************************************************************************/

int przetwarzaj_opcje(int argc, char **argv, w_opcje *wybor);

#endif


/*******************************************************/
/* Testowe wywołanie funkcji przetwarzaj_opcje         */
/* PRE:                                                */
/*      brak                                           */
/* POST:                                               */
/*      brak                                           */
/*******************************************************/

/*
int main(int argc, char ** argv) {
  w_opcje opcje;

  printf("%d\n", przetwarzaj_opcje(argc,argv,&opcje));

  return 0;
}
*/
