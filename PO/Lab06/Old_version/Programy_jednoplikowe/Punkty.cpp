#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define LICZBA_PUNKTOW 15

class Punkty
{
  std::vector<float> _punkty;
public: 
  Punkty(){srand(time(NULL)); for(int i=0;i<LICZBA_PUNKTOW;++i) _punkty.push_back(std::rand());}

  float Oblicz_Srednia()
  {
    float tmp=0;
    for(float aa : _punkty)
      tmp+=aa;
    return tmp/_punkty.size();
  }

  void Wyswietl_Z_Indeksem(){
    for(std::vector<int>::size_type i = 0; i != _punkty.size(); i++) std::cout<<" "<<i<<".  "<<_punkty[i]<<std::endl;
  }

};

int main()
{
  Punkty Pkt;
  Pkt.Wyswietl_Z_Indeksem();
  std::cout<<"Srednia: "<<Pkt.Oblicz_Srednia()<<std::endl;
}
