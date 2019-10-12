#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


struct Statystyka {
  // Przypisanie %% gdzies w petli przed wywolaniem WczytajRownanie %%
  unsigned int WszystkieDzialania;
  //
  unsigned int PoprawnyZapis;
  // Przypisanie w funkcji "WykonajDzialania" w WyrazenieAlgeb.cpp
  unsigned int PoprawnyWynik;
  //
  float ProcentWynikow;
  // Przypisanie w funkcji "WykonajDzialania" w WyrazenieAlgeb.cpp
  unsigned int IloscDodajOdejmij;
  // Przypisanie w funkcji "WykonajDzialania" w WyrazenieAlgeb.cpp
  unsigned int IloscMnozDziel;
  //  unsigned int 
};


/********************************************************************/
/*                                                                  */
/* Funkcja zeryje wszystki dane struktury typu Statystyka           */
/*                                                                  */
/********************************************************************/
void Zeruj(Statystyka & Stat);


#endif
