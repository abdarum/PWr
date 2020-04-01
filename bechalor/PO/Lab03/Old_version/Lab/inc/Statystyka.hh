#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <cstdio>
#include <iomanip> 
#include <iostream>
using namespace std;


struct Statystyka {
  // Przypisanie %% gdzies w petli przed wczytaniem rownania %%
  unsigned int WszystkieDzialania;
  // Przypisanie %% gdzies w petli przed wczytaniem rownania %%
  unsigned int PoprawnyZapis;
  // Przypisanie w funkcji "WykonajDzialania" w WyrazenieAlgeb.cpp
  unsigned int PoprawnyWynik;
  // Przypisanie w funkcji "WykonajDzialania" w WyrazenieAlgeb.cpp
  unsigned int IloscDodajOdejmij;
  // Przypisanie w funkcji "WykonajDzialania" w WyrazenieAlgeb.cpp
  unsigned int IloscMnozDziel;


};




/********************************************************************/
/*                                                                  */
/* Funkcja zeryje wszystki dane struktury typu Statystyka           */
/*                                                                  */
/********************************************************************/
void Zeruj(Statystyka & Stat);


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wyswietlanie danych ze struktury       */
/*   typu Statystyka                                                */
/*                                                                  */
/********************************************************************/
ostream& operator << (ostream& wyj,Statystyka Stat);


#endif
