#include <memory>
#include <iostream>
#include <cmath>
#include <string>
#include <list>


enum TypObiektu { TO_Owoc, TO_Agrest, TO_Czeresnie, TO_Ananas };

class Owoc {
  unsigned int _ilosc_pestek;
  double _promien;
  double _wysokosc;
  //  sring _kolor;
public:
  Owoc(){ _ilosc_pestek=0;_promien=0;_wysokosc=0;}
  Owoc(unsigned int Pest, double Prom,double Wys){_ilosc_pestek=Pest;_promien=Prom;_wysokosc=Wys;}
  ~Owoc(){}

  virtual std::string Zwroc_Nazwe() const {return "Owoc";} 
  virtual int Zwroc_Ilosc_Pestek() const {return _ilosc_pestek;}
  virtual double Zwroc_Objetosc() const {return 0;}
  double Promien() const {return _promien;}
  void Promien(double Pr){ _promien=Pr;}
  double Wysokosc() const {return _wysokosc;}
  void Wysokosc(double Wys){_wysokosc=Wys;}

};



class Czeresnie: public Owoc {
  unsigned int _ilos_w_kisci;
public:
  Czeresnie(){Owoc(); _ilos_w_kisci=0; }
  Czeresnie(unsigned int Pest, double Prom,unsigned int Ilosc){Owoc( Pest, Prom,0); _ilos_w_kisci=Ilosc; }
  ~Czeresnie(){}
  virtual std::string Zwroc_Nazwe() const {return "Czeresnie";} 
  virtual int Zwroc_Ilosc_Pestek() const {return Zwroc_Ilosc_Pestek();} 
  virtual double Zwroc_Objetosc() const {return _ilos_w_kisci*4*M_PI*pow(Owoc::Promien(),3)/3; } 
  unsigned int Ilosc_W_Kisci() const {return _ilos_w_kisci;}
  void Ilosc_W_Kisci(unsigned int Ilosc) {_ilos_w_kisci=Ilosc;}
  
};


class Ananas: public Owoc {
public:
  Ananas(){Owoc();}
  Ananas(double Prom,double Wys){Owoc(0, Prom,Wys); }
  ~Ananas(){}
  virtual std::string Zwroc_Nazwe() const {return "Ananas";}
  virtual int Zwroc_Ilosc_Pestek() const {return 0;} 
  virtual double Zwroc_Objetosc() const {return M_PI*pow(Owoc::Promien(),2)*Owoc::Wysokosc()/3;} 

};


class Agrest: public Owoc{
public:
  Agrest(){Owoc();}
  Agrest(unsigned int Pest, double Prom,double Wys){Owoc( Pest, Prom,Wys); }
  ~Agrest(){}
  virtual std::string Zwroc_Nazwe() const {return "Agrest";} 
  virtual int Zwroc_Ilosc_Pestek() const {return Zwroc_Ilosc_Pestek();} 
  virtual double Zwroc_Objetosc() const {return M_PI*pow(Owoc::Promien(),2)*Owoc::Wysokosc();} 
  

};


class Fabryka {
public:
  std::shared_ptr<Owoc> UtworzObiekt( TypObiektu  TypOb )
  {
    switch (TypOb) {
    case TO_Owoc: return std::make_shared<Owoc>();
    case TO_Czeresnie: return std::make_shared<Czeresnie>();
    case TO_Agrest: return std::make_shared<Agrest>();
    case TO_Ananas: return std::make_shared<Ananas>();
    }
    return std::make_shared<Agrest>(); // To tylko po to, aby kompilator
    // nie twierdził, że metoda nic nie zwraca. Ta instrukcja
    // i tak nigdy się nie wykona.
  }
};

int main(){

  Owoc Ow;
  std::list<std::shared_ptr<Owoc>> L_Ow;
  std::shared_ptr<Owoc> L_tmp_Ow;
  Fabryka Fab;
  for(int i=0;i<3;++i)L_Ow.push_back(Fab.UtworzObiekt(TO_Czeresnie));
  for(int i=0;i<3;++i)L_Ow.push_back(Fab.UtworzObiekt(TO_Agrest));
  for(int i=0;i<3;++i)L_Ow.push_back(Fab.UtworzObiekt(TO_Ananas));

  
  
  

  int i=0;
  for (std::list<std::shared_ptr<Owoc>>::iterator it=L_Ow.begin(); it != L_Ow.end(); ++it)
    std::cout<<"Nazwa "<<i++<<" : "<< (*it)->Zwroc_Nazwe()<<std::endl;
  //std::cout<<std::endl;
}
