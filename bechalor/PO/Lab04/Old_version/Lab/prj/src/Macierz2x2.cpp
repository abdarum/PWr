#include "Macierz2x2.hh"



Macierz2x2::Macierz2x2(float a)
{
  float alpha=M_PI*a/180.0;
  _Tab[0][0]=cos(alpha);
  _Tab[0][1]=-sin(alpha);
  _Tab[1][0]=sin(alpha);
  _Tab[1][1]=cos(alpha);
}


Wektor2D Macierz2x2::operator *(Wektor2D& Wektor)
{
  Wektor2D tmp;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      tmp[i]+=_Tab[i][j]*Wektor[j];
    }
  }
  Wektor= tmp;
  return Wektor;
}


std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac)
{
  std::cout << std::fixed;

  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      std::cout<<std::setprecision(30)<<Mac._Tab[i][j]<<'\t';
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
  return Strm;
}
