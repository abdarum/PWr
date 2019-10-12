#include "Robot.hh"


void Robot::Domyslne_Wartosci()
{
  _wierzcholki[0]=Wektor2D(0,0);
  _wierzcholki[1]=Wektor2D(7,0);
  _wierzcholki[2]=Wektor2D(0,-10);
  _wierzcholki[3]=Wektor2D(-10,-10);
  _wierzcholki[4]=Wektor2D(-10,10);
  _wierzcholki[5]=Wektor2D(0,10);
}


void Robot::ObrocOKat(double a)
{
  Domyslne_Wartosci();
  _kat_obrotu+=a;
  _kat_obrotu=fmod(_kat_obrotu,360.0);
  for(int i=0;i<LICZBA_PUNKTOW;++i)
    _wierzcholki[i]=Macierz2x2(_kat_obrotu)*_wierzcholki[i];
}

std::ostream& operator << (std::ostream &Strm, const Robot &Rob)
{
  for(int i=0;i<LICZBA_PUNKTOW;++i)
    std::cout<<(Rob.Wartosc(i)+Rob.Wsp_Globalne())<<std::endl; 
  return Strm;
}


void Robot::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<(LICZBA_PUNKTOW+1);++i){
    (Wsp_Globalne()+_wierzcholki[i>=LICZBA_PUNKTOW?(i%LICZBA_PUNKTOW)+1:i]).WyswietlWspolrzedneFormatGnuplot(StrmWy);
  }

}

bool Robot::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku)
{
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  for(int i=0;i<(LICZBA_PUNKTOW+1);++i){
    //    std::cout<<"test iteracji : "<<i<<"   | "<<LICZBA_PUNKTOW<<std::endl;
    _wierzcholki[i>=LICZBA_PUNKTOW?(i%LICZBA_PUNKTOW)+1:i].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  }
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
