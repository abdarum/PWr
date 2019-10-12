#include <iostream>

using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/
enum Symbol {e, a, b, c, d};
Symbol TabliczkaDodawania[5][5] = {{e, a, b, c, d},{a, d, e, b, c},{b, e, c, d, a},{c, b, d, a, e},{d, c, a, e, b}};
Symbol TabliczkaMnozenia[5][5] = {{e, e, e, e, e},{e, a, b, c, d},{e, b, a, d, c},{e, c, d, b, a},{e, d, c, a, b}};

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/
Symbol Dodaj(Symbol Arg1, Symbol Arg2);


/*
  Definicja przeciazen operatorow
*/ 
Symbol operator + (Symbol Arg1, Symbol Arg2);


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
  //  Symbol wynik_alg, wynik_ope;
  Symbol wynik_fun, y, x;

  /*
  cout<<"Podaj liczby w formacie x y \n gdzie x jest pierwsza liczba uzyta do operacji a y druga"<<endl;
 
  cout << "Podaj x";
  cin >> x ;
  cout << "Podaj y";
  cin >> y;
  */


  x=a,y=c;
  cout<<"Uzyte parametry to:x="<<x<<" i y="<<y<<endl;

  wynik_fun=Dodaj(y,x);
  cout << "Dodaj: " << wynik_fun << endl;

  wynik_fun=operator + (y,x);
  cout << "Operator +: " << wynik_fun << endl;

  wynik_fun=y+x;
  cout << "+: " << wynik_fun << endl;

  /* czesc ktora sie tutaj znajdowala w oryginalnym pliku usunalem 
     aby nie powstawaly niepotrzebne bledy podczas kompilacji */
  
}


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/*         *** FUNKCJE ***         */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


/********************************************************************/
/*                                                                  */
/* Funkcja odpowiada za dodawanie dwóch argumentow. Wynik dodawania */
/*   jest taki jak w tabelce dostarczonej do zadania.               */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/* Wartosci zwracane to {0,1,2,3,4} dla odpowiednio {e,a,b,c,d}     */
/*                                                                  */
/********************************************************************/
Symbol Dodaj(Symbol Arg1, Symbol Arg2) 
{
  return TabliczkaDodawania[Arg2][Arg1];
}




/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*                                 */ 
/* *** PRZECIAZENIE OPERATOROW *** */
/*                                 */
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/


/********************************************************************/
/*                                                                  */
/* Przeciazenie odpowiada za dodawanie dwóch argumentow. Wynik      */
/*   dodawania jest taki jak w tabelce dostarczonej do zadania.     */
/* Argumenty powinny nalezec do zbioru {e, a, b, c, d}              */
/*                                                                  */
/********************************************************************/
Symbol operator + (Symbol Arg1, Symbol Arg2)
{
  return TabliczkaDodawania[Arg2][Arg1];
}

