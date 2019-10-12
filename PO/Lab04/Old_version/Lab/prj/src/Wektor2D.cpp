#include "Wektor2D.hh"

void Wektor2D::WyswietlWspolrzedneFormatGnuplot(std::ostream& StrmWy) const
{
  StrmWy<<std::setw(16)<<std::fixed<<std::setprecision(10)<< _x;
  StrmWy<<std::setw(16)<<std::fixed<<std::setprecision(10)<< _y <<std::endl;

}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
  std::cin>>Wek[0];
  std::cin>>Wek[1];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
  std::cout << std::fixed;
  std::cout<<std::setprecision(6)<<Wek[0]<<'\t'<<Wek[1]<<std::endl<<std::fixed;;
  return Strm;
}
