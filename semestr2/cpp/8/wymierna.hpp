#include <bits/stdc++.h>
using namespace std;

namespace obliczenia
{
  class Wymierna
  {
  private:
    int licz;
    int mian;
  public:
    Wymierna(int l, int m); //konstruktor z licznikiem i mianownikiem
    Wymierna(int x); //konstruktor konwertujący z wartości typu int
    //konstruktor domyślny, ustawiający wartość liczby wymiernej na zero (czyli ułamek 0/1)
    Wymierna(const Wymierna &) = default;
    Wymierna & operator = (const Wymierna &) = default; //zeby operatory dzialaly

    void Skroc();
    int NWD(int l, int m);
    int get_l() const {return licz;};
    int get_m() const {return mian;};

    // friend ostream & operator << (ostream & wy, const Wymierna & x);

    //operatory
    // Wymierna & operator + (const Wymierna &); //nwm czemu tu musi byc & ale bez niego sa bledy...
    // Wymierna & operator - (const Wymierna &);
    Wymierna & operator * (const Wymierna &);
    Wymierna & operator / (const Wymierna &);
    Wymierna operator - (); //przeciwna
    Wymierna operator ! (); //odwrotna
    operator double();
    explicit operator int(); //czemu explicit
  };
}

//wyjatki