#include "wymierna.hpp"
using namespace obliczenia;

Wymierna::Wymierna(int l, int m)
{
  if(m == 0) //mianownik zawsze był > 0
  {
    throw "Pamietaj cholero: nie dziel przez zero!";
    // throw NieDzielPrzezZero("Nie dziel przez zero");
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
  this->licz /= a;
  this->mian /= a;
}

Wymierna::Wymierna(int x)
{
  licz = x;
  mian = 1;
  Skroc();
}

Wymierna & Wymierna::operator * (const Wymierna & w1)
{
  if(this->licz * w1.get_l() > INT_MAX || this->mian * w1.get_m() > INT_MAX)
  {
    throw "Przekroczono zakres inta";
    // throw PrzekroczonoZakres("Przekroczono zakres inta");
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
    throw "Przekroczono zakres inta";
    // throw PrzekroczonoZakres("Przekroczono zakres inta");
  }
  if(w1.get_l() == 0)
  {
    throw "Pamietaj cholero: nie dziel przez zero!";
    // throw NieDzielPrzezZero("Nie dziel przez zero");
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
    throw "Pamietaj cholero: nie dziel przez zero!";
    // throw NieDzielPrzezZero("Nie dziel przez zero");
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
