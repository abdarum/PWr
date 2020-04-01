#include "Statystyka.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie funkcje,
 *  ktore beda okreslac dopuszczalne metody dostepu
 *  i akceptowalny zbior operacji na strukturze Statystyka.
 */

void Zeruj(Statystyka & Stat)
{
  Stat.WszystkieDzialania=0;
  Stat.PoprawnyZapis=0;
  Stat.PoprawnyWynik=0;
  Stat.ProcentWynikow=0.0;
  Stat.IloscDodajOdejmij=0;
  Stat.IloscMnozDziel=0;
}
