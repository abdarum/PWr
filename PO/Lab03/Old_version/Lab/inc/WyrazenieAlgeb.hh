#ifndef WYRAZENIEALGEB_HH
#define WYRAZENIEALGEB_HH

#include "Symbol.hh"
#include "Statystyka.hh"


#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

 
struct WyrazenieAlgeb {
  Symbol Arg1;        // Pierwszy wczytany argument
  char ZnakDzialania; // Zmienna przechowuje znak jaki został wprowadzony
  Symbol Arg2;        // Drugi wczytany argument
  Symbol WczytanyWynikDzialania; 
  Symbol PrawidlowyWynikDzialania;
  bool WynikiRowne;   // true gdy sa rowne
};


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/*         *** FUNKCJE ***         */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/



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
/* Funkcja odpowiada za znalezienie i zwrocenie elementu przeciwnego*/
/*   do elementu podanego jako Arg1                                 */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol ZnajdzPrzeciwny(Symbol Arg1);


/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za znalezienie i zwrocenie elementu odwrotnego */
/*   do elementu podanego jako Arg1                                 */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol ZnajdzOdwrotny(Symbol Arg1);


/********************************************************************/
/*                                                                  */
/* Funkcja czysci flage bledy ktora zatrzymuje obliczenie nastepnego*/
/*   dzialania. Nalezy stosowac ja po kazdejwykonanej operacji.     */
/*                                                                  */
/********************************************************************/
void ZerujBledy();


/********************************************************************/
/*                                                                  */
/* Funkcja zeryje wszystki dane struktury typu WyrazenieAlgeb       */
/*                                                                  */
/********************************************************************/
void Zeruj(WyrazenieAlgeb & Dzialania);


/********************************************************************/
/*                                                                  */
/* Funkcja wykonuje wykonuje obliczenia w celu sprawdzenia          */
/*   wprowadzonego dzialania. Operuje na strukturze typu            */
/*   WyrazenieAlgeb                                                 */
/*                                                                  */
/********************************************************************/
void WykonajDzialania(WyrazenieAlgeb & Dzialania,Statystyka& Stat);



/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/* *** PRZECIAZENIE OPERATOROW *** */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/



/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za zwrocenie wartosci elementu przy ktorym*/
/*   stoi + (Wartosc argumentu sie nie zmienia).                    */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator + (Symbol Arg1);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za dodawanie dwóch argumentow. Wynik      */
/*   dodawania jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator + (Symbol Arg1, Symbol Arg2);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za zwrocenie wartosci przeciwnej dla      */
/*   argumentu przy ktorym stoi.                                    */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator - (Symbol Arg1);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za odejmowanie dwóch argumentow.          */
/*   Odejmowanie jest zrealizowane jako dodawanie elementu          */
/*   przeciwnego.                                                   */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator - (Symbol Arg1, Symbol Arg2);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za mnozenie dwóch argumentow. Wynik       */
/*    mnozenia jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator * (Symbol Arg1, Symbol Arg2);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za dzielenie dwóch argumentow. Dzieleni  */
/*    jest realizowane poprzez pomnozenie przez liczbe odwrotna.    */
/* Arg2 nie moze byc e                                              */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator / (Symbol Arg1, Symbol Arg2);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za potegowanie.                           */
/* Arg2 nie moze byc e                                              */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator ^ (Symbol Arg1, Symbol Arg2);

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

/********************************************************************/
/*                                                                  */
/* Przeciazenie wczytuje z stdin rownanie. Powiadamia o bledach     */
/*   skladni. Nie pokazuje informacji o dobrych lub zlych wynikach. */
/*   W razie bledow ustawia flage failbit na 1                      */
/*                                                                  */
/********************************************************************/
istream& operator >> (istream& wej,WyrazenieAlgeb& Dzialania);

/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za wyswietlanie zawartosci struktury      */
/*   WyrazenieAlgeb. Wypisuje ona wprowadzone dane i jesli          */
/*   wprowadzony wynik nie jest prawidlowy dla podanego dzialania   */
/*   to wyswietla poprawny wynik                                    */
/*                                                                  */
/********************************************************************/
ostream& operator << (ostream& wyj,WyrazenieAlgeb Dzialania);

#endif
