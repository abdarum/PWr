#ifndef ZBIOROBJEKTOW
#define ZBIOROBJEKTOW


#include "Przeszkoda.hh"
#include "Sciezka.hh"
#include "Robot.hh"
#include "Objekt_Graficzny.hh"

/*!
 * \file
 *
 * \brief Deklaracja klasy typu ZbiorObjektow
 *
 * Plik zawiera deklaracje klasy ZbiorObjektow
 */

/*!
 *\brief Modeluje informacje dotyczace zbioru Objektów
 *
 * Modeluje zestaw informacji dotyczacych zbioru wierzchołków.
 * Udostępnia także metody umozliwiające aktualizowanie wartosci 
 * a także zwracanie ich.
 */
class ZbiorObjektow: public Objekt_Graficzny, public Robot, public Przeszkoda, public Sciezka
{


};
#endif
