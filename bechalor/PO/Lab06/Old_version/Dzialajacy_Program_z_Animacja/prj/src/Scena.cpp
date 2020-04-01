#include "Scena.hh"




bool Scena::ZapisWspolrzednychDoPlikuFormatGnuplot(const char  *sNazwaPliku)
{
  std::ofstream  StrmPlikowy;
  
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
    std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
    return false;
  }
    

  Sciez.WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  //Sciez.Animacja_Sciezki(Rob,1,2000,StrmPlikowy);
  StrmPlikowy<<std::endl;
  Rob.WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

bool Scena::Animacja_Sciezki_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Sciezka Sciezka_Animowana,Robot Robot_Animowany,double dlugosc,int microseconds)
{
  std::ofstream  StrmPlikowy;
  
  Sciezka_Animowana.Przygotuj_Animacje_Sciezki(Robot_Animowany,dlugosc);

  while(!Sciezka_Animowana.Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }
      
      Sciezka_Animowana.Animacja_Sciezki_Z_Robotem(StrmPlikowy,Robot_Animowany);
      StrmPlikowy.close();
     
      Lacze.Rysuj();
      usleep(microseconds);      
    }
  return !StrmPlikowy.fail();
}




bool Scena::Animacja_Obrotu_FormatGnuplot(PzG::LaczeDoGNUPlota Lacze,const char *sNazwaPliku,Sciezka Sciezka_Animowana,Robot Robot_Animowany,int microseconds,double a)
{
  std::ofstream  StrmPlikowy;
  
  while(!Robot_Animowany.Koniec_Animacji())
    { 
      StrmPlikowy.open(sNazwaPliku);
      if (!StrmPlikowy.is_open())  {
	std::cerr<<":(  Operacja otwarcia do zapisu \""<< sNazwaPliku << "\"";
	std::cerr<<std::endl<< ":(  nie powiodla sie." << std::endl;
	return false;
      }
      
      Sciezka_Animowana.WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
      StrmPlikowy<<std::endl;
      
      
      Robot_Animowany.Animacja_Obrotu_Robota(StrmPlikowy,a);
      StrmPlikowy.close();
     
      Lacze.Rysuj();
      usleep(microseconds);      
    }
  return !StrmPlikowy.fail();
}











