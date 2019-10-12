#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <cstdio>
#include <iomanip> 
#include <iostream>
using namespace std;


class Statystyka {
private:
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


public:
/********************************************************************/
/*                                                                  */
/* Funkcja zeryje wszystki dane struktury typu Statystyka           */
/*                                                                  */
/********************************************************************/
  void Zeruj();
  void ZwiekszWszystkieDzialania(){ ++WszystkieDzialania; }
  int ZwrocWszystkieDzialania(){ return WszystkieDzialania; }
  void ZwiekszPoprawnyZapis(){ ++PoprawnyZapis; }
  int ZwrocPoprawnyZapis(){ return PoprawnyZapis; }
  void ZwiekszPoprawnyWynik(){ ++PoprawnyWynik; }
  int ZwrocPoprawnyWynik(){ return PoprawnyWynik; }
  void ZwiekszIloscDodajOdejmij(){ ++IloscDodajOdejmij; }
  int ZwrocIloscDodajOdejmij(){ return IloscDodajOdejmij; }
  void ZwiekszIloscMnozDziel(){ ++IloscMnozDziel; }
  int ZwrocIloscMnozDziel(){ return IloscMnozDziel; }
  void Wyswietl();
};




/********************************************************************/
/*                                                                  */
/* Funkcja zeryje wszystki dane struktury typu Statystyka           */
/*                                                                  */
/********************************************************************/
//void Zeruj(Statystyka & Stat);


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wyswietlanie danych ze struktury       */
/*   typu Statystyka                                                */
/*                                                                  */
/********************************************************************/
//ostream& operator << (ostream& wyj,Statystyka Stat);


#endif
