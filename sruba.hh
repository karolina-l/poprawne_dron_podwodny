#ifndef SRUBA
#define SRUBA

#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "graniastoslup.hh"



using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Sruba dziedziczaca publicznie po klasie Graniastoslup
*/
class Sruba: public Graniastoslup{

protected:
  /*!
  * \brief srodek drona (potrzebne do obrotow)
  */
  TWektor<double,3> sr_drona;

public:
  /*!
  * \brief Konstruktor obiektu klasy Sruba
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka sruby
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * \param5 TWektor<double,3> sr_dr - wspolrzedne srodka drona
  * Metoda korzysta z konstruktora klasy Graniastoslup
  */
  Sruba(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w, const TWektor<double,3> &sr_dr): Graniastoslup(plot,sr,mat,w), sr_drona(sr_dr){}
  /*!
  * \brief wirtualny destruktor klasy Sruba
  */
  virtual ~Sruba(){}
  /*!
  * \brief Metoda pozwalajaca na zmiane kata sruby wzgledem osi OZ
  * \param1 double kat - kat obrotu
  */
  void zmien_kat(double kat) override;
  /*!
  * \brief Metoda pozwalajaca na zmiane polozenia sruby
  * \param1 TWektor<double,3> w - wektor zmiany polozenia
  */
  void zmien_polozenie(const TWektor<double,3> &w) override;
  /*!
  * \brief Metoda pozwalajaca na zmiane kata sruby wzgledem osi OX
  */
  void obrot_sruby();

};



#endif
