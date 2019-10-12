#include "ZbiorWierzcholkow.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy ZbiorWierzcholkow, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
/*
void ZbiorWierzcholkow::DlugosciBokow() const
{
  double tmp[LICZBA_PUNKTOW_PROSTOKAT];
  double key;
  bool rowne[2]={0,0};

  for(int i=0;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
    tmp[i]=sqrt(pow((_zb_wierzcholkow[i][0]-_zb_wierzcholkow[i==3? 0 : i+1][0]),2)+pow((_zb_wierzcholkow[i][1]-_zb_wierzcholkow[i==3? 0 : i+1][1]),2));

  // sortowanie (wieksze elementy na poczatku)
  for(int j,i=1;i<LICZBA_PUNKTOW_PROSTOKAT;++i)
    {
      key=tmp[i];
      for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	tmp[j+1]=tmp[j];
      tmp[j+1]=key;
    }

  // Do testow 
    {
    std::cout<<" Odleglosci bokow to:"<<std::endl;
    for(int i=0;i<4;++i)
      std::cout<<std::setprecision(16)<<tmp[i]<<std::endl;  
    
    std::cout<<std::numeric_limits<double>::epsilon()<<std::endl;
    } 
    

  if(abs(tmp[0]-tmp[1])<(std::numeric_limits<double>::epsilon()))
    std::cout<<":) Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
  else
    std::cout<<":O Dluzsze przeciwlegle boki nie sa rowne!!!"<<std::endl;

  if(abs(tmp[2]-tmp[3])<(std::numeric_limits<double>::epsilon()))
    std::cout<<":) Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
  else
    std::cout<<":O Krotsze przeciwlegle boki nie sa rowne!!!"<<std::endl;
}
*/


bool ZbiorWierzcholkow::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku) const
{
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }
  
  WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


void ZbiorWierzcholkow::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  //for(std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  
  for(unsigned int i=0;i<(_zb_wierzcholkow.size()+1);++i)
    _zb_wierzcholkow[i%_zb_wierzcholkow.size()].WyswietlWspolrzedneFormatGnuplot(StrmWy);
}

std::ostream& operator << (std::ostream &Strm, const ZbiorWierzcholkow &Zb_Wierzch)
{
  for(int i=0;i<Zb_Wierzch.Rozmiar();++i)
    std::cout<<Zb_Wierzch[i]<<std::endl; 
  return Strm;
}
