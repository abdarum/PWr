
#include "Statystyka.hh"


using namespace std;


/*
 *  Tutaj nalezy zdefiniowac odpowiednie funkcje,
 *  ktore beda okreslac dopuszczalne metody dostepu
 *  i akceptowalny zbior operacji na strukturze Statystyka.
 */

void Statystyka::Zeruj()
{
  WszystkieDzialania=0;
  PoprawnyZapis=0;
  PoprawnyWynik=0;
  IloscDodajOdejmij=0;
  IloscMnozDziel=0;
}




void Statystyka::Wyswietl()
{
  float  ProcentWynikow=0.0;
  ProcentWynikow=((float)ZwrocPoprawnyWynik()*100)/(float)ZwrocPoprawnyZapis();
  
  cout<<"Statystyka: "<<endl;
  cout<<"              Ilosc wszystkich wyrazen: ";
  cout<<ZwrocWszystkieDzialania()<<endl;
  cout<<"    Ilosc poprawnie zapisanych wyrazen: ";
  cout<<ZwrocPoprawnyZapis()<<endl;  
  cout<<"    Ilosc wyrazen z poprawnym wynikiem: ";
  cout<<ZwrocPoprawnyWynik()<<endl;  
  cout<<"   Procentowo ilosc poprawnych wynikow: "; 
  cout<<setiosflags(ios::fixed)<<setprecision(1)<<ProcentWynikow<< "%"<<endl;
  cout<<"Ilosc operacji odejmowania i dodawania: ";
  cout<<ZwrocIloscDodajOdejmij()<<endl;  
  cout<<"   Ilosc operacji mnozenia i dzielenia: ";
  cout<<ZwrocIloscMnozDziel()<<endl;  
}



/*
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

*/
