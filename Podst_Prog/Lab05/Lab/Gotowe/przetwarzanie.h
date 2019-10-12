#ifndef PRZETWARZANIE
#define PRZETWARZANIE
#include "odczyt_zapis_obrazu.h"

/*******************************************************/
/* Funkcja zmienia poziom czerni u bieli               */
/* PRE:                                                */
/*       biel  - zmienna sluzy do zmiany poiomow jest  */
/*  to wartosc podawana w liczbach calkowitych         */
/*  odpowiadajocych procentom - dla 80% jest to        */
/*  liczba 80                                          */
/*       czern - podobnie jak w przypadku bieli        */
/*                                                     */
/*  czern i biel powinny byc z przedzialu od 0 do 100  */
/* POST:                                               */
/*      program przypisuje tablicy w strukturze        */
/*      wartosci po wykonaniu operacji zmiany poziomow */
/*******************************************************/
void zmiana_poziomow(obraz_struct *obraz,int czern,int biel);


/*******************************************************/
/* Funkcja proguje obraz                               */
/* PRE:                                                */
/*       prog - wartosc progu uzywana przy progowaniu. */
/*                                                     */
/*  Wartosc podawana w liczbach calkowitych            */
/*  odpowiadajocych procentom - dla 50% jest to        */
/*  liczba 50                                          */
/*                                                     */
/*  wartosc progu powinna byc od 0 do 100              */
/* POST:                                               */
/*      program przypisuje tablicy w strukturze        */
/*      wartosci po wykonaniu operacji zmiany poziomow */
/*******************************************************/
void progowanie(obraz_struct *obraz,int prog);



/*******************************************************/
/* Funkcja polproguje czern                            */
/* PRE:                                                */
/*    prog - wartosc progu uzywana przy polprogowaniu. */
/*                                                     */
/*  Wartosc podawana w liczbach calkowitych            */
/*  odpowiadajocych procentom - dla 50% jest to        */
/*  liczba 50                                          */
/*                                                     */
/*  wartosc progu powinna byc od 0 do 100              */
/* POST:                                               */
/*      program przypisuje tablicy w strukturze        */
/*      wartosci po wykonaniu operacji zmiany poziomow */
/*******************************************************/
void progowanie_czerni(obraz_struct *obraz,int prog);


/*******************************************************/
/* Funkcja polproguje biel                             */
/* PRE:                                                */
/*    prog - wartosc progu uzywana przy polprogowaniu. */
/*                                                     */
/*  Wartosc podawana w liczbach calkowitych            */
/*  odpowiadajocych procentom - dla 50% jest to        */
/*  liczba 50                                          */
/*                                                     */
/*  wartosc progu powinna byc od 0 do 100              */
/* POST:                                               */
/*      program przypisuje tablicy w strukturze        */
/*      wartosci po wykonaniu operacji zmiany poziomow */
/*******************************************************/
void progowanie_bieli(obraz_struct *obraz,int prog);


/*******************************************************/
/* Funkcje nizej podane                                */
/* PRE:                                                */
/*      wskaznik na strukture typu obraz_struct        */
/* POST:                                               */
/*      program przypisuje tablicy w strukturze        */
/*      wartosci po wykonaniu operacji podanych        */
/*      w nazwach funkcji                              */
/*******************************************************/

void negatyw(obraz_struct *obraz);
void konturowanie(obraz_struct *obraz);
void rozciaganie_histogramu(obraz_struct *obraz);
void rozmywanie_poziome(obraz_struct *obraz);
void rozmywanie_pionowe(obraz_struct *obraz);

#endif
