#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Macierz2x2.hh"

/*!
 * \file
 *
 * \brief Deklaracja klasy typu prostakat
 */

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Wektor2D _prostokat[4];

  public:

  Prostakat(){for(int i=0;i<4;++i)_prostokat[0]=Wektor2D(); }
  //  Obroc(float alpha){}
  //  Prostakat(Wektor W0,Wektor W1,Wektor W2,Wektor W3);
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  /*!
   * \brief Obraca prostakat o kat a
   */
  /*
   * \brief Obracenie Prostakota o kat
   */
  void ObracOKata(float a);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostokat    &Pr
                          );


#endif
