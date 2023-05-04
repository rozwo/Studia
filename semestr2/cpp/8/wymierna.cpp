#include "wymierna.hpp"
using namespace obliczenia;

Wymierna::Wymierna(int l, int m)
{
  if(m == 0) //mianownik zawsze był > 0
  {
    throw "dzielenie przez 0";
    // throw dzielenie_przez_0("dzielenie przez 0");
  }
  if(m < 0)
  {
    licz = -l;
    mian = -m;
  }
  else
  {
    licz = l;
    mian = m;
  }
  Skroc(); //największy wspólny dzielnik licznika i mianownika zawsze był = 1
}

int Wymierna::NWD(int a, int b) //najw wsp dziel
{
  while(a!=b)
  {
    if(a>b)
    {
      a-=b;
    }
    else
    {
      b-=a;
    }
  }
  return a;
}

void Wymierna::Skroc()
{
  int a;
  if(this->licz < 0)
  {
    a = -this->licz;
  }
  else
  {
    a = this->licz;
  }
  a = NWD(a,this->mian); //bo nwd licze na nieujemnych
  if(a > INT_MAX)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  this->licz /= a;
  this->mian /= a;
}

Wymierna::Wymierna(int x)
{
  licz = x;
  mian = 1;
  Skroc();
}

int Wymierna::NWW(int a, int b) //najm wsp wiel
{
  int c = NWD(a,b);
  return a/c * b;
}

Wymierna & Wymierna::operator + (const Wymierna & w1)
{
  int nowy_mian = NWW(this->mian,w1.get_m());
  int nowy_licz = this->licz * (nowy_mian/this->mian) + w1.get_l() * (nowy_mian/w1.get_m());
  int a;
  if(nowy_licz < 0)
  {
    a = -nowy_licz;
  }
  else
  {
    a = nowy_licz;
  }
  int nwd = NWD(a,nowy_mian);
  if(nowy_licz/nwd > INT_MAX || nowy_mian/nwd > INT_MAX)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  int l = nowy_licz / nwd;
  int m = nowy_mian / nwd;
  Wymierna w2(l,m);
  return w2;
}

Wymierna & Wymierna::operator - (const Wymierna & w1)
{
  int nowy_mian = NWW(this->mian,w1.get_m());
  int nowy_licz = this->licz * (nowy_mian/this->mian) - w1.get_l() * (nowy_mian/w1.get_m());
  int a;
  if(nowy_licz < 0)
  {
    a = -nowy_licz;
  }
  else
  {
    a = nowy_licz;
  }
  int nwd = NWD(a,nowy_mian);
  if(nowy_licz/nwd > INT_MAX || nowy_mian/nwd > INT_MAX)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  int l = nowy_licz / nwd;
  int m = nowy_mian / nwd;
  Wymierna w2(l,m);
  return w2;
}

Wymierna & Wymierna::operator * (const Wymierna & w1)
{
  if(this->licz * w1.get_l() > INT_MAX || this->mian * w1.get_m() > INT_MAX)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  int l = this->licz * w1.get_l();
  int m = this->mian * w1.get_m();
  Wymierna w2(l, m);
  return w2;
}

Wymierna & Wymierna::operator / (const Wymierna & w1)
{
  if(this->licz * w1.get_m() > INT_MAX || this->mian * w1.get_l() > INT_MAX)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  if(w1.get_l() == 0)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  int l = this->licz * w1.get_m();
  int m = this->mian * w1.get_l();
  Wymierna w2(l, m);
  return w2;
}

Wymierna Wymierna::operator ! () //odwrotna
{
  if(this->licz == 0)
  {
    throw "przekroczenie zakresu";
    // throw przekroczenie_zakresu("przekroczenie zakresu");
  }
  if(this->licz < 0)
  {
    int tmp = -this->licz;
    this->licz = -this->mian;
    this->mian = tmp;
  }
  else
  {
    int tmp = this->licz;
    this->licz = this->mian;
    this->mian = tmp;
  }
  return *this;
}

Wymierna Wymierna::operator - () //przeciwna
{
  this->licz = -this->licz;
  return *this;
}

Wymierna::operator double() //operator rzutowania na typ double
{
  return (double)this->licz/this->mian; //nwm czemu ale dziala XDDD
}

Wymierna::operator int() //operator jawnego rzutowania na typ int
{
  return this->licz/this->mian;
}


//wyjatki

// dzielenie_przez_0::dzielenie_przez_0(const string t)
// {
//   tekst = t;
// }

const string dzielenie_przez_0::zapis()
{
  return tekst.c_str();
}

// przekroczenie_zakresu::przekroczenie_zakresu(const string t)
// {
//   tekst = t;
// }

const string przekroczenie_zakresu::zapis()
{
  return tekst.c_str();
}
