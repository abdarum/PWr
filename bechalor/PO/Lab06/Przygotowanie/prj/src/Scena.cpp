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
    
  for (std::vector<Prostokat>::iterator it = _przeszkody.begin() ; it != _przeszkody.end(); ++it)
    {
      (*it).WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
      StrmPlikowy<<std::endl;
    }
  //  _przeszkody.back().WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  StrmPlikowy<<std::endl;
  StrmPlikowy<<std::endl;

  Sciez.WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  //Sciez.Animacja_Sciezki(Rob,1,2000,StrmPlikowy);
  StrmPlikowy<<std::endl;
  Rob.WyswietlWspolrzedneFormatGnuplot(StrmPlikowy);
  
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
