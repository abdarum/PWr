#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


struct Statystyka {
  unsigned int WszystkieDzialania;
  unsigned int PoprawnyZapis;
  unsigned int PoprawnyWynik;
  float ProcentWynikow;
  unsigned int IloscDodajOdejmij;
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
