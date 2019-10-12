#include <iostream>

using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/

/*
  Definicja przeciazen operatorow
*/

void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl;
}

int main()
{
 Symbol wynik_alg, wynik_ope, wynik_fun;

/*--------------------
  Po wpisaniu odpowiednich wyrazen znaki komentujace
  ponizszy zestaw instrukcji nalezy usunac.

 wynik_alg = WYRAZENIE_ALG_1; // <- Wyrazenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_1; // <- Wyrazenie wykorzystujace funkcje
 wynik_ope = WYRAZENIE_OPE_1; // <- Wyrazenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_2; // <- Wyrazenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_2; // <- Wyrazenie wykorzystujace funkcje
 wynik_ope = WYRAZENIE_OPE_2; // <- Wyrazenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_3; // <- Wyrazenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_3; // <- Wyrazenie wykorzystujace funkcje
 wynik_ope = WYRAZENIE_OPE_3; // <- Wyrazenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_4; // <- Wyrazenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_4; // <- Wyrazenie wykorzystujace funkcje
 wynik_ope = WYRAZENIE_OPE_4; // <- Wyrazenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);
 */
}
