
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

void Bryla::ObrocOKat(double a,char os_obrotu,int count)
{
  Macierz3x3 tmp(a,os_obrotu);
  for(;count>0;--count)
    for(int i=0;i<LICZBA_PUNKTOW;++i)
      {
	_bryla[i]=tmp*_bryla[i];
      }
}

void Bryla::ObrocOKat(Macierz3x3 Mac,int count)
{
  for(;count>0;--count)
    for(int i=0;i<LICZBA_PUNKTOW;++i)
      {
	_bryla[i]=Mac*_bryla[i];
      }
}

/*
bool Bryla::DlugosciBokow() const
{
  double tmp[LICZBA_BOKOW];
  double key;
  
  int n;
  for(n=0;n<LICZBA_BOKOW/3;++n)
    {
      //    std::cout<<'\t'<<n%4*2<<'\t'<<n%4*2+1<<std::endl;
      tmp[n]=sqrt(pow((_bryla[n%4*2][0]-_bryla[n%4*2+1][0]),2)+pow((_bryla[n%4*2][1]-_bryla[n%4*2+1][1]),2)+pow((_bryla[n%4*2][2]-_bryla[n%4*2+1][2]),2));
    }      
  for(;n<LICZBA_BOKOW*2/3;++n)
    {
      //    std::cout<<'\t'<<n%4*2+1<<'\t'<<(n%4*2+3)%8<<std::endl;
      tmp[n]=sqrt(pow((_bryla[n%4*2+1][0]-_bryla[(n%4*2+3)%8][0]),2)+pow((_bryla[n%4*2+1][1]-_bryla[(n%4*2+3)%8][1]),2)+pow((_bryla[n%4*2+1][2]-_bryla[(n%4*2+3)%8][2]),2));
    }
  for(;n<LICZBA_BOKOW;++n) 
    {
      //    std::cout<<'\t'<<n%4*2<<'\t'<<(n%4*2+2)%8<<std::endl;
      tmp[n]=sqrt(pow((_bryla[n%4*2][0]-_bryla[(n%4*2+2)%8][0]),2)+pow((_bryla[n%4*2][1]-_bryla[(n%4*2+2)%8][1]),2)+pow((_bryla[n%4*2][2]-_bryla[(n%4*2+1)%8][2]),2));
    }


  // Do testow
  for(int i=0;i<LICZBA_PUNKTOW;++i)
    tmp[i]=sqrt(pow((_bryla[i][0]-_bryla[(i==LICZBA_PUNKTOW-1)? 0 : i+1][0]),2)+pow((_bryla[i][1]-_bryla[(i==LICZBA_PUNKTOW-1)? 0 : i+1][1]),2)+pow((_bryla[i][2]-_bryla[(i==LICZBA_PUNKTOW-1)? 0 : i+1][2]),2));
  

    // Do testow
    // sortowanie w 3 grupach
  for(n=0;n<3;++n)
    for(int j,i=n*4;i<LICZBA_BOKOW*n/3;++i)
      {
	key=tmp[i];
	for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	  tmp[j+1]=tmp[j];
	tmp[j+1]=key;
      }
  
  
  // sortowanie (wieksze elementy na poczatku)
  for(int j,i=1;i<LICZBA_BOKOW;++i)
    {
      key=tmp[i];
      for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	tmp[j+1]=tmp[j];
      tmp[j+1]=key;
    }
    
  
  // Do testow 
    {
    std::cout<<" Odleglosci bokow to:"<<std::endl;
    for(int i=0;i<LICZBA_BOKOW;++i)
      std::cout<<std::setprecision(16)<<tmp[i]<<std::endl;  
    
    //    std::cout<<std::numeric_limits<double>::epsilon()<<std::endl;
    } 

    for(int i=0;i<LICZBA_BOKOW;i+=2)
    if(!(abs(tmp[i  ]-tmp[i   +1])<(std::numeric_limits<double>::epsilon()))) 
      {
	std::cout<<tmp[i/2] <<"   "<<tmp[i/2 +1]<<"  ";

	std::cout<<i<<"   ";
	std::cout<<":O Wybrane przeciwlegle boki nie sa rowne!!!"<<std::endl;
	return 0;
      }
  std::cout<<":) Przeciwlegle boki sa sobie rowne."<<std::endl;
  return 1;
}
*/
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

  /*
  for(int i=0;i<(LICZBA_PUNKTOW+2);++i){
    //    std::cout<<"test iteracji : "<<i<<"   | "<<LICZBA_PUNKTOW<<std::endl;
    _bryla[i%LICZBA_PUNKTOW].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
    if(i%2==1) StrmPlikowy<<std::endl;
  }
  */

  _bryla[0].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[1].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  _bryla[1].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[3].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  _bryla[3].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[0].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  _bryla[0].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[2].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  _bryla[2].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[3].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  _bryla[3].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[1].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  _bryla[1].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  _bryla[2].WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);

  
  
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}




double Bryla::PoleBoku()
{
  double pole;
  double wysokosc=0,dlugosc=0;
  Wektor3D srodek;
  
  
   dlugosc=sqrt(pow((_bryla[1][0]-_bryla[2][0]),2)+pow((_bryla[1][1]-_bryla[2][1]),2)+pow((_bryla[1][2]-_bryla[2][2]),2));
   /*
   srodek=_bryla[1]+_bryla[2];
   srodek=srodek/2;
   
wysokosc=sqrt(pow((_bryla[1][0]-srodek[0]),2)+pow((_bryla[1][1]-srodek[1]),2)+pow((_bryla[1][2]-srodek[2]),2));


 pole=wysokosc*dlugosc/2;
 return pole;
  */
 std::cout<<dlugosc<<std::endl;
 pole = (pow(dlugosc,2)*sqrt(3))/4;
 return pole;
}
