
#include "Statystyka.hh"


using namespace std;


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
  Stat.IloscDodajOdejmij=0;
  Stat.IloscMnozDziel=0;
}

ostream& operator << (ostream& wyj,Statystyka Stat)
{
  float ProcentWynikow=0.0;
  ProcentWynikow=((float)Stat.PoprawnyWynik*100)/(float)Stat.PoprawnyZapis;
  
  cout<<"Statystyka: "<<endl;
  cout<<"              Ilosc wszystkich wyrazen: ";
  cout<<Stat.WszystkieDzialania<<endl;
  cout<<"    Ilosc poprawnie zapisanych wyrazen: ";
  cout<<Stat.PoprawnyZapis<<endl;  
  cout<<"    Ilosc wyrazen z poprawnym wynikiem: ";
  cout<<Stat.PoprawnyWynik<<endl;  
  cout<<"   Procentowo ilosc poprawnych wynikow: "; 
  cout<<setiosflags(ios::fixed)<<setprecision(1)<<ProcentWynikow<< "%"<<endl;  cout<<"Ilosc operacji odejmowania i dodawania: ";
  cout<<Stat.IloscDodajOdejmij<<endl;  
  cout<<"   Ilosc operacji mnozenia i dzielenia: ";
  cout<<Stat.IloscMnozDziel<<endl;  
  return wyj;
}

