#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Plik znaduje sie elementarny przyklad demonstrujacy problemy
 * skonczonej reprezentaji liczb w zapisie binarnym.
 *
 * Przyklad zostal stworzony na potrzeby zajec z "Programowania obiektowego"
 * prowadzonych na kierunku Automatyka i Robotyka. Plik ten moze byc
 * kopiowany i wykorzystywany bez zadnych ograniczen pod warunkiem, 
 * ze jest kopiowany w calosci bez usuwania niniejszego komentarza.
 *
 * 1. Skompiluj ten program i zobacz wynik
 *
 * 2. Zamien wartosci 0.5 w podstawieniach na 0.25, tzn.
 *
 *  float   ZmFloat  = 0.25;
 *  float   ZmDouble = 0.25;
 *
 *  Skompiluj program, uruchom go i zobacz wynik.
 *
 * 3. Zamien wartosc 0.25 w podstawieniach na 0.2, tzn.
 *
 *  float   ZmFloat  = 0.2;
 *  float   ZmDouble = 0.2;
 *
 *  Skompiluj program, uruchom go i zobacz wynik.
 *  Czy sa jakies roznice? Jezeli tak, to z czego one wynikaja?
 */

int main()
{
  float   ZmFloat  = 1.1;
  double  ZmDouble = 1.1;

  cout << "Wartosc zm. float  = " << setprecision(30) << ZmFloat << endl;
  cout << "Wartosc zm. double = " << setprecision(30) << ZmDouble << endl;
  return 0;
}
