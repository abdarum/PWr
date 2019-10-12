#ifndef FUNKCJE_STOSU
#define FUNKCJE_STOSU

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define DL_LINI 1024

typedef struct element {
  int wart;
  struct element *nast;
}t_elem;

/*******************************************************/
/* Funkcja dodaje komorke typu t_elem na wierzch stosu */
/* PRE:                                                */
/*      poprawnie zainicjowany stos                    */
/* POST:                                               */
/*      dodajnie komurki typu t_elem na wierzch stosu  */
/*  o wartosci "wart" element                          */
/*******************************************************/
void push(t_elem **stos,int element);



/*******************************************************/
/* Funkcja zdejmuje komokne ze  stosu                  */
/* PRE:                                                */
/*      poprawnie zainicjowany stos                    */
/* POST:                                               */
/*      zdjecie komurki komorki ze stosu zwracajac     */
/*   wartosc pola "wart"                               */
/*   w razie braku elementu funkcja wyswietla blad na  */
/*   stderr                                            */
/*******************************************************/
void pop(t_elem **stos,int *elem);


/*******************************************************/
/* Funkcja sprawdza czy stos jest pusty                */
/* PRE:                                                */
/*      poprawnie zainicjowany stos                    */
/* POST:                                               */
/*      jezeli tak zwraca 0 jezeli nie -1              */
/*******************************************************/
int empty(t_elem *stos);


/*******************************************************/
/* Funkcja wyswietla wartosci znajdujace sie na stosie */
/* PRE:                                                */
/*      poprawnie zainicjowany stos                    */
/* POST:                                               */
/*      wyswietlenie na stdout                         */
/*******************************************************/
void print(t_elem *stos);


/*******************************************************/
/* Funkcja inicjuje pusty stos                         */
/* PRE:                                                */
/*      poprawnie zainicjowany stos                    */
/* POST:                                               */
/*      stos==NULL                                     */
/*******************************************************/
void inicjuj(t_elem **stos);

#endif
