#include "Prostokat.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostokat, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

void Prostokat::Ustaw(double x_0, double y_0, double x_1, double y_1, double x_2, double y_2, double x_3, double y_3)
{
  _prostokat[0].Ustaw(x_0,y_0);
  _prostokat[1].Ustaw(x_1,y_1);
  _prostokat[2].Ustaw(x_2,y_2);
  _prostokat[3].Ustaw(x_3,y_3);
}

void Prostokat::Ustaw(Wektor2D Wekt_0,Wektor2D Wekt_1,Wektor2D Wekt_2,Wektor2D Wekt_3)
{
  _prostokat[0]=Wekt_0;
  _prostokat[1]=Wekt_1;
  _prostokat[2]=Wekt_2;
  _prostokat[3]=Wekt_3;
}

void Prostokat::ObrocOKat(float a,int count)
{
  Macierz2x2 tmp(a);
  for(;count>0;--count)
    for(int i=0;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
      {
	_prostokat[i]=tmp*_prostokat[i];
      }
}

void Prostokat::DlugosciBokow() const
{
  double tmp[LICZBA_PUNKTOW_PROSTOKAT];
  double key;
  bool rowne[2]={0,0};

  for(int i=0;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
    tmp[i]=sqrt(pow((_prostokat[i][0]-_prostokat[i==3? 0 : i+1][0]),2)+pow((_prostokat[i][1]-_prostokat[i==3? 0 : i+1][1]),2));

  // sortowanie (wieksze elementy na poczatku)
  for(int j,i=1;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
    {
      key=tmp[i];
      for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	tmp[j+1]=tmp[j];
      tmp[j+1]=key;
    }

  // Do testow 
  /*  {
    std::cout<<" Odleglosci bokow to:"<<std::endl;
    for(int i=0;i<4;++i)
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

void Prostokat::PrzesunOWektor(Wektor2D const Wek)
{
  for(int i=0;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
    _prostokat[i]+=Wek;
}


std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr)
{
  for(int i=0;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
    std::cout<<Pr[i]; 
  return Strm;
}


bool Prostokat::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku){
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  for(int i=0;i<LICZBA_PUNKTOW_PROSTOKAT+1;++i)
    _prostokat[i==LICZBA_PUNKTOW_PROSTOKAT? 0 : i].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


void Prostokat::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<(LICZBA_PUNKTOW_PROSTOKAT+1);++i){
    //    (Wsp_Globalne()+_wierzcholki[i>=LICZBA_PUNKTOW?(i%LICZBA_PUNKTOW)+1:i]).WyswietlWspolrzedneFormatGnuplot(StrmWy);
    _prostokat[i%LICZBA_PUNKTOW_PROSTOKAT].WyswietlWspolrzedneFormatGnuplot(StrmWy);

 }

}
