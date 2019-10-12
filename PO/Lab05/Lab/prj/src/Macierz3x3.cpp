#include "Macierz3x3.hh"


void Macierz3x3::UstawAlpha(double a,char os_obrotu)
{
  Zeroj_Macierz();
  double alpha=M_PI*a/180.0;

  switch(os_obrotu)
    {
    case 'x':
      _Tab[0][0]=1;
      _Tab[1][1]=cos(alpha);
      _Tab[1][2]=-sin(alpha);
      _Tab[2][1]=sin(alpha);
      _Tab[2][2]=cos(alpha);

      break;
    case 'y':
      _Tab[0][0]=cos(alpha);
      _Tab[0][2]=sin(alpha);
      _Tab[1][1]=1;
      _Tab[2][0]=-sin(alpha);
      _Tab[2][2]=cos(alpha);
	break;
    case 'z':
      _Tab[0][0]=cos(alpha);
      _Tab[0][1]=-sin(alpha);
      _Tab[1][0]=sin(alpha);
      _Tab[1][1]=cos(alpha);
      _Tab[2][2]=1;
      break;
    }
}


Macierz3x3 Macierz3x3::Macierz_Obrotu(double a,char os_obrotu)
{
  Macierz3x3 Mac;
  Mac.UstawAlpha(a,os_obrotu);
 *this=*this*Mac;
 return Mac;
}

Wektor3D Macierz3x3::operator *(Wektor3D& Wektor) const
{
  Wektor3D tmp;
  for(int i=0;i<ROZMIAR_MACIERZY;++i){
    for(int j=0;j<ROZMIAR_MACIERZY;++j){
      tmp[i]+=_Tab[i][j]*Wektor[j];
    }
  }
  Wektor= tmp;
  return Wektor;
}

Macierz3x3 Macierz3x3::operator *(Macierz3x3& Mac) const
{
  Macierz3x3 tmp;
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


std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &Mac)
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

std::istream& operator >> (std::istream &Strm, Macierz3x3 &Mac)
{
  for(int i=0;i<ROZMIAR_MACIERZY;++i){
    for(int j=0;j<ROZMIAR_MACIERZY;++j){
      std::cin>>Mac._Tab[i][j];
    }
  }
  return Strm;
}
