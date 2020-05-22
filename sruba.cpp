#include "sruba.hh"
#include "m_obrotu.hh"
#include "dron.hh"
#include <math.h>

using namespace std;

void Sruba::obrot_sruby() //problemy z dzialaniem
{
  M_obr obr;
  obr=obr.utworz_mRx(30);

    for(int j=0; j<12; j++)
    {
      t[j]=t[j]-srodek;
    }
    for(int i=0; i<12; i++)
    {
      t[i]=obr*t[i];
    }

    for(int i=0; i<12; i++)
    {
      t[i]=t[i]+srodek;
    }

  this->usun();
  //this->Graniastoslup::rysuj_ksztalt();
  //gnuplot->redraw();

}

  void Sruba::zmien_kat(double kat)
  {
      M_obr obr;

      obr=obr.utworz_mRz(kat);
      for(int i=0; i<12; i++)
      {
        t[i]=t[i]-sr_drona;
      }
      for(int i=0; i<12; i++)
      {
        t[i]=obr*t[i];
      }

      for(int i=0; i<12; i++)
      {
        t[i]=t[i]+sr_drona;
      }
      this->usun();
  }

void Sruba::zmien_polozenie(const TWektor<double,3> &w)
{

  sr_drona=sr_drona+w;
  srodek=srodek+w;
  for(int i=0; i<12; i++)
  {
    t[i]=t[i]+w;
  }
  gnuplot->erase_shape(nazwa);
}
