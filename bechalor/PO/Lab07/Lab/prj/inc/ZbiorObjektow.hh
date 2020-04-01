#ifndef FABRYKA
#define FABRYKA


#include "Przeszkoda.hh"
#include "Sciezka.hh"
#include "Robot.hh"
#include "Objekt_Graficzny.hh"

/*!
 * \file
 *
 * \brief Deklaracja klasy typu Fabryka
 *
 * Plik zawiera deklaracje klasy Fabryka
 */

/*!
 *\brief Modeluje informacje dotyczace Fabryki
 *
 * Modeluje zestaw informacji dotyczacych zbioru wierzchołków.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class Fabryka : public Objekt_Graficzny, public Robot, public Przeszkoda, public Sciezka
{
public:
  std::shared_ptr<Objekt_Graficzny> UtworzObiekt( Tryb_Pracy  TypOb )
  {
    switch (TypOb) {
    case Ob_Objekt_Graficzny: return std::make_shared<Objekt_Graficzny>();
    case Ob_Robot: return std::make_shared<Robot>();
    case Ob_Przeszkoda: return std::make_shared<Przeszkoda>();
    case Ob_Sciezka: return std::make_shared<Sciezka>();
    }
    return std::make_shared<Przeszkoda>(); // To tylko po to, aby kompilator
    // nie twierdził, że metoda nic nie zwraca. Ta instrukcja
    // i tak nigdy się nie wykona.
  }

  static Fabryka & getSingleton()
  {
    static Fabryka singleton;
    return singleton;
  }
private:
  Fabryka(){}
  Fabryka(const Fabryka&){ }
};



#endif

