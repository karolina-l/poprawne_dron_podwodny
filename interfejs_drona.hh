#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Interfejs dziedziczaca publicznie po klasie Prostopadloscian
*/
class Interfejs: public Prostopadloscian{

public:
  /*!
  * \brief Konstruktor obiektu klasy Interfejs
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * Metoda korzysta z konstruktora klasy Prostopadloscian
  */
Interfejs(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w):Prostopadloscian(plot,sr,mat,w){}
  /*!
  * \brief wirtualny destruktor klasy Interfejs
  */
virtual ~Interfejs(){};

};

#endif
