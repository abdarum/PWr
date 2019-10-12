#include <iostream>

int main()
{

  double Wektor[2];
  double tmp[2];
  double _Tab[2][2];

  std::cout<<"Wczytaj macierz"<<std::endl;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      std::cin>>_Tab[i][j];
    }
  }


  std::cout<<"Wczytaj wektor"<<std::endl;
  for(int j=0;j<2;++j){
    std::cin>>Wektor[j];
  }


  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      tmp[i]+=_Tab[i][j]*Wektor[j];
    }
  }

  std::cout<<"Wypisz wektor"<<std::endl;
  for(int j=0;j<2;++j){
    std::cout<<tmp[j]<<'\t';
  }


  return 0;
}

/*



*/
