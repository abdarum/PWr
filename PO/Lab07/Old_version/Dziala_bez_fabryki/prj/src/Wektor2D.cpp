#include "Wektor2D.hh"

void Wektor2D::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    StrmWy<<std::setw(16)<<std::fixed<<std::setprecision(10)<< _wart[i];
  StrmWy<<std::endl;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    std::cin>>Wek[i];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
  for(int i=0;i<WYMIAR_WEKTORA;++i)
    Strm<<std::setw(16)<<std::fixed<<std::setprecision(10)<< Wek[i];
  return Strm;
}
