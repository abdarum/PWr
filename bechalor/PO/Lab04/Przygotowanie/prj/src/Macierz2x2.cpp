#include "Macierz2x2.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz2x2, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */



void Macierz2x2::operator *(Wektor2D& Wektor)
{
  Wektor2D tmp;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      tmp[i]+=_Tab[i][j]*Wektor[j];
    }
  }
  Wektor= tmp;
}


Macierz2x2::Macierz2x2(float a)
{
  float alpha=M_PI*a/180.0;
  _Tab[0][0]=cos(alpha);
  _Tab[0][1]=-sin(alpha);
  _Tab[1][0]=sin(alpha);
  _Tab[1][1]=cos(alpha);
}
