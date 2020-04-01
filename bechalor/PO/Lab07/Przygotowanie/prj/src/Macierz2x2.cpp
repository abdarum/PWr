#include "Macierz2x2.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz2x2, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */




Wektor2D Macierz2x2::operator *(Wektor2D Wektor) const
{
  Wektor2D tmp;
  for(int i=0;i<ROZMIAR_MACIERZY;++i){
    for(int j=0;j<ROZMIAR_MACIERZY;++j){
      tmp[i]+=_Tab[i][j]*Wektor[j];
    }
  }
  Wektor= tmp;
  return Wektor;
}

Macierz2x2 Macierz2x2::operator *(Macierz2x2& Mac) const
{
  Macierz2x2 tmp;
  for(int i=0;i<ROZMIAR_MACIERZY;++i){
    for(int j=0;j<ROZMIAR_MACIERZY;++j){
      for(int k=0;k<ROZMIAR_MACIERZY;++k){
	tmp.Wartosc(i,j)+=_Tab[i][k]*Mac.Wartosc(k,j);
      }
    }
  }
  Mac = tmp;
  return Mac;
}


void Macierz2x2::UstawAlpha(double a)
{
  Zeroj_Macierz();
  double alpha=M_PI*a/180.0;
  _Tab[0][0]=cos(alpha);
  _Tab[0][1]=-sin(alpha);
  _Tab[1][0]=sin(alpha);
  _Tab[1][1]=cos(alpha);
}

std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac)
{
  std::cout << std::fixed;

  for(int i=0;i<ROZMIAR_MACIERZY;++i){
    for(int j=0;j<ROZMIAR_MACIERZY;++j){
      Strm<<std::setw(22)<<std::fixed<<std::setprecision(16)<<Mac._Tab[i][j];
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
  return Strm;
}

std::istream& operator >> (std::istream &Strm, Macierz2x2 &Mac)
{
  for(int i=0;i<ROZMIAR_MACIERZY;++i){
    for(int j=0;j<ROZMIAR_MACIERZY;++j){
      std::cin>>Mac._Tab[i][j];
    }
  }
  return Strm;
}


Macierz2x2 Macierz2x2::Macierz_Obrotu(double a)
{
  Macierz2x2 Mac;
  Mac.UstawAlpha(a);
 *this=*this*Mac;
 return Mac;
}


