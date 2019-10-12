
#include "Bryla.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Bryla, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

void Bryla::Ustaw(double Wart[LICZBA_PUNKTOW*WYMIAR_WEKTORA])
{
  for(int i=0;i<LICZBA_PUNKTOW*WYMIAR_WEKTORA;++i)
    _bryla[i/WYMIAR_WEKTORA].Ustaw_Wsp(Wart[i],i%WYMIAR_WEKTORA);
  
}

void Bryla::Ustaw(Wektor3D Wart[LICZBA_PUNKTOW])
{
  for(int i=0;i<LICZBA_PUNKTOW;++i)
    _bryla[i]=Wart[i];
}

void Bryla::ObrocOKat(float a,int count)
{
  Macierz2x2 tmp(a);
  for(;count>0;--count)
    for(int i=0;i<LICZBA_PUNKTOW;++i)
      {
	_bryla[i]=tmp*_bryla[i];
      }
}

void Bryla::DlugosciBokow() const
{
  double tmp[LICZBA_PUNKTOW];
  double key;
  bool rowne[2]={0,0};

  for(int i=0;i<LICZBA_PUNKTOW;++i)
    tmp[i]=sqrt(pow((_bryla[i][0]-_bryla[i==3? 0 : i+1][0]),2)+pow((_bryla[i][1]-_bryla[i==3? 0 : i+1][1]),2));

  // sortowanie (wieksze elementy na poczatku)
  for(int j,i=1;i<LICZBA_PUNKTOW;++i)
    {
      key=tmp[i];
      for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	tmp[j+1]=tmp[j];
      tmp[j+1]=key;
    }

  // Do testow 
  /*  {
    std::cout<<" Odleglosci bokow to:"<<std::endl;
    for(int i=0;i<LICZBA_PUNKTOW;++i)
      std::cout<<std::setprecision(16)<<tmp[i]<<std::endl;  
    
    std::cout<<std::numeric_limits<double>::epsilon()<<std::endl;
    } */


  if(abs(tmp[0]-tmp[1])<(std::numeric_limits<double>::epsilon()))
    std::cout<<":) Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
  else
    std::cout<<":O Dluzsze przeciwlegle boki nie sa rowne!!!"<<std::endl;

  if(abs(tmp[2]-tmp[3])<(std::numeric_limits<double>::epsilon()))
    std::cout<<":) Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
  else
    std::cout<<":O Krotsze przeciwlegle boki nie sa rowne!!!"<<std::endl;
}

void Bryla::PrzesunOWektor(Wektor3D const Wek)
{
  for(int i=0;i<LICZBA_PUNKTOW;++i)
    _bryla[i]+=Wek;
}


std::ostream& operator << (std::ostream &Strm, const Bryla &Pr)
{
  for(int i=0;i<LICZBA_PUNKTOW;++i)
    std::cout<<Pr[i]<<std::endl; 
  return Strm;
}


bool Bryla::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku){
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  for(int i=0;i<(LICZBA_PUNKTOW+1);++i){
    //    std::cout<<"test iteracji : "<<i<<"   | "<<LICZBA_PUNKTOW<<std::endl;
    _bryla[i==LICZBA_PUNKTOW? 0 : i].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  }
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
