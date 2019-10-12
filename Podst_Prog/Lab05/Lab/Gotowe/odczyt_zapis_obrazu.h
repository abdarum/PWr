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
  w_rgb rgbw;
}obraz_struct;


/*******************************************************/
/* Funkcje czyta wymiary obrazu oraz alokuje tablice   */
/* PRE:                                                */
/*      plik_we plik z ktorego funkcja ma czytac       */
/*   powinien byc to plik ppm                          */
/*      wskaznik na strukture typu obraz_struct        */
/* POST:                                               */
/*      program wczytuje wartosci wymx i wymy do       */
/*  struktury z pliku plik_we oraz alokuje tablice rgb */
/*******************************************************/
int czytaj_wymiary(FILE *plik_we,obraz_struct *obraz);


/*******************************************************/
/* Funkcje czyta plik do tablicy w strukturze          */
/* PRE:                                                */
/*      plik_we plik z ktorego funkcja ma czytac       */
/*   powinien byc to plik ppm                          */
/*      wskaznik na strukture typu obraz_struct        */
/* POST:                                               */
/*      program przypisuje tablicy wartosci wczytane   */
/*   z pliku plik_we                                   */
/*******************************************************/
int czytaj(FILE *plik_we,obraz_struct *obraz);


/*******************************************************/
/* Funkcje zapisuje tablice z obrazem do pliku         */
/* PRE:                                                */
/*      plik_wy plik do ktorego funkcja ma zapisac     */
/*   tablice z obrazem. Moze byc to typ ppm lub pgm    */
/*      wskaznik na strukture typu obraz_struct        */
/* POST:                                               */
/*      program wypisuje do pliku wartosci tablic      */
/*   ze struktury w zaleznosci od typu obrazu          */
/*******************************************************/
int zapisz(FILE *plik_wy,obraz_struct *obraz);


/*******************************************************/
/* Funkcje konwertuje plik rgb do czarnobialego        */
/* PRE:                                                */
/*      wskaznik na strukture typu obraz_struct        */
/* POST:                                               */
/*    program alokuje tablice dla obrazu czarnobialego */
/* i przypisuje tablicy wartosci sredniej arytmetycznej*/
/*   z tablic r, g i b                                 */
/*******************************************************/
void zrob_czarno_bialy(obraz_struct *obraz);


/*******************************************************/
/* Funkcja zeruje opcje struktury wywolanej przez opcje*/
/* PRE:                                                */
/*      poprawnie zainicjowany argument obraz (!=NULL) */
/* POST:                                               */
/*      "wyzerowana" struktura obraz wybranych opcji   */
/*******************************************************/
void wyzeruj_obraz(obraz_struct *obraz);


/*******************************************************/
/* Funkcja zwalnia dynamiczne tablice ze struktury obraz*/
/* PRE:                                                */
/*      poprawnie zainicjowany argument obraz (!=NULL) */
/* POST:                                               */
/*      "wyzerowana" struktura obraz wybranych opcji   */
/*******************************************************/
void zwolnij_obraz(obraz_struct *obraz);


/*******************************************************/
/* Funkcja wyswietla plik o nazwie podanej w tablicy   */
/*   char                                              */
/* PRE:                                                */
/*      napis ktory zawiera nazwe pliku do otwarcia    */
/*      napis nie moze byc pusty                       */
/* POST:                                               */
/*     brak                                            */
/*******************************************************/
void wyswietl(char *n_pliku);


#endif
