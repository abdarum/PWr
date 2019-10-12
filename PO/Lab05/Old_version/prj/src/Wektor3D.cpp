#include "Wektor3D.hh"

void Wektor3D::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    StrmWy<<std::setw(16)<<std::fixed<<std::setprecision(10)<< _wart[i];
  StrmWy<<std::endl;

}

std::istream& operator >> (std::istream &Strm, Wektor3D &Wek)
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    std::cin>>Wek[i];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor3D &Wek)
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    Strm<<std::setw(16)<<std::fixed<<std::setprecision(10)<< Wek[i];
  return Strm;
}
