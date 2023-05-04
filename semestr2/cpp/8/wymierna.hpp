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

    friend ostream & operator << (ostream & wy, const Wymierna & x);

    //operatory
    Wymierna operator + (const Wymierna &);
    Wymierna operator - (const Wymierna &);
    Wymierna operator * (const Wymierna &);
    Wymierna operator / (const Wymierna &);
    Wymierna operator - (); //przeciwna
    Wymierna operator ! (); //odwrotna

    explicit operator double(); //operator rzutowania na typ double
    explicit operator int(); //operator jawnego rzutowania na typ int
    //z wykładu: "Przy operatorach konwersji można użyć słowa kluczowego explicit aby uniknąć konwersji niejawnej."
  };
}

//wyjatki
class wyjatek_wymierny : public exception //logic_error nie dziala ale nwm dlaczego
{
    const string tekst;
public:
    explicit wyjatek_wymierny(const string zapis) : tekst(zapis) {};
    virtual string zapis() const noexcept  { return tekst; };
};

class dzielenie_przez_0 : public wyjatek_wymierny
{
public:
    explicit dzielenie_przez_0(const string zapis) : wyjatek_wymierny(zapis) {};
};

class przekroczenie_zakresu : public wyjatek_wymierny
{
public:
    explicit przekroczenie_zakresu(const string zapis) : wyjatek_wymierny(zapis) {};
};
