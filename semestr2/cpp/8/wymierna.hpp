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
    Wymierna(); //konstruktor domyślny, ustawiający wartość liczby wymiernej na zero (czyli ułamek 0/1)

    void Skroc();
    int NWD(int l, int m);
    int NWW(int l, int m);
    int get_l() const {return licz;};
    int get_m() const {return mian;};

    // friend ostream & operator << (ostream & wy, const Wymierna & x);

    //operatory
    Wymierna operator + (const Wymierna &);
    Wymierna operator - (const Wymierna &);
    Wymierna operator * (const Wymierna &);
    Wymierna operator / (const Wymierna &);
    Wymierna operator - (); //przeciwna
    Wymierna operator ! (); //odwrotna

    operator double(); //operator rzutowania na typ double
    explicit operator int(); //operator jawnego rzutowania na typ int
    //z wykładu "Przy operatorach konwersji można użyć słowa kluczowego explicit aby uniknąć konwersji niejawnej."
  };
}

//wyjatki

class wyjatek_wymierny : public logic_error
{
  protected:
    string tekst;
  public:
    wyjatek_wymierny() = default;
};

class dzielenie_przez_0 : public wyjatek_wymierny
{
  public:
    // dzielenie_przez_0() = default;
    dzielenie_przez_0(const string t);
    virtual const string zapis();
    // virtual ~dzielenie_przez_0() = default;
};

class przekroczenie_zakresu : public wyjatek_wymierny
{
  public:
    // przekroczenie_zakresu() = default;
    przekroczenie_zakresu(const string t);
    virtual const string zapis();
    // virtual ~przekroczenie_zakresu() = default;
};