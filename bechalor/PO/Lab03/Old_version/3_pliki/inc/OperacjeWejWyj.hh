#ifndef OPERACJEWEJWYJ
#define OPERACJEWEJWYJ

#include "Symbol.hh"
#include "WyrazenieAlgeb.hh"
#include "Statystyka.hh"

#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wczytywanie danych typu symbol z std   */
/*   cin. Argumentowi Arg zostanie przypisana wartosc wczytana ze   */
/*   strumienia. W razie niepowodzenia funkcja zwraca wartosc false */
/*   w przeciwnym razie zwraca wartosc true                         */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
bool WczytajSymbol(Symbol& Arg);


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wyswietlanie danych typu symbol na std */
/*   cout w takiej postaci w jakiej sa zadeklarowane w kodzie.      */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
void WypiszSymbol(Symbol Arg);


/********************************************************************/
/*                                                                  */
/* Funkcja wyswietla wartosci wczytanego dzialania. Wypisuje        */
/*   wprowadzone dane i jesli wprowadzony wynik nie jest prawidlowy */
/*   dla podanego dzialania wyswietla poprawny wynik                */
/*                                                                  */
/********************************************************************/
//void WyswietlWynik(WyrazenieAlgeb Dzialania);


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wczytywanie danych typu symbol z std   */
/*   cin. Argumentowi Arg zostanie przypisana wartosc wczytana ze   */
/*   strumienia. W razie niepowodzenia zostanie ustawiona flaga     */
/*   failbit                                                        */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
istream& operator >> (istream& wej,Symbol& Arg);  


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wyswietlanie danych typu symbol na std */
/*   cout w takiej postaci w jakiej sa zadeklarowane w kodzie.      */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
ostream& operator << (ostream& wyj,Symbol Arg);



#endif
