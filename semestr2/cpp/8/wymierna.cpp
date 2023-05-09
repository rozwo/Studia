#include "wymierna.hpp"

wyjatek_wymierny::wyjatek_wymierny(string message) : logic_error(message) {};

namespace obliczenia
{
  Wymierna::Wymierna(int l, int m)
  {
    if(m == 0) //mianownik zawsze był > 0
    {
      throw dzielenie_przez_0("dzielenie przez 0");
    }
    if(abs(l) > INT_MAX || abs(m) > INT_MAX)
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
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
    int a = abs(this->licz);
    if(a > INT_MAX || abs(this->mian) > INT_MAX)
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
    }
    a = NWD(a,this->mian); //bo nwd licze na nieujemnych
    this->licz /= a;
    this->mian /= a;
  }

  Wymierna::Wymierna(int x)
  {
    if(abs(x) > INT_MAX)
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
    }
    licz = x;
    mian = 1;
    Skroc();
  }

  Wymierna::Wymierna()
  {
    licz = 0;
    mian = 1;
  }

  int Wymierna::NWW(int a, int b) //najm wsp wiel
  {
    int c = NWD(a,b);
    return a/c * b;
  }

  Wymierna Wymierna::operator + (const Wymierna & w1)
  {
    int nowy_mian = NWW(this->mian,w1.get_m());
    int a = this->licz * (nowy_mian/this->mian);
    int b = w1.get_l() * (nowy_mian/w1.get_m());
    if(b>0 && a > INT_MAX - b || b<0 && a < INT_MIN + b)
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
    }
    int nowy_licz = a + b;
    int nwd = NWD(abs(nowy_licz),nowy_mian);
    int l = nowy_licz / nwd;
    int m = nowy_mian / nwd;
    Wymierna w2(l,m);
    return w2;
  }

  Wymierna Wymierna::operator - (const Wymierna & w1)
  {
    int nowy_mian = NWW(this->mian,w1.get_m());
    int a = this->licz * (nowy_mian/this->mian);
    int b = w1.get_l() * (nowy_mian/w1.get_m());
    if(b<0 && a > INT_MAX - b || b>0 && a < INT_MIN + b)
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
    }
    int nowy_licz = a - b;
    int nwd = NWD(abs(nowy_licz),nowy_mian);
    int l = nowy_licz / nwd;
    int m = nowy_mian / nwd;
    Wymierna w2(l,m);
    return w2;
  }

  Wymierna Wymierna::operator * (const Wymierna & w1)
  {
    if((this->licz > 0 && w1.get_l() > 0 || this->licz < 0 && w1.get_l() < 0) && abs(this->licz) > INT_MAX / abs(w1.get_l()) ||
       (this->licz < 0 && w1.get_l() > 0 || this->licz > 0 && w1.get_l() < 0) && abs(this->licz) * -1 < INT_MIN / abs(w1.get_l()))
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
    }
    int l = this->licz * w1.get_l();
    int m = this->mian * w1.get_m();
    Wymierna w2(l, m);
    return w2;
  }

  Wymierna Wymierna::operator / (const Wymierna & w1)
  {
    if(abs(this->licz) > INT_MAX / abs(w1.get_m()) || abs(this->mian) > INT_MAX / abs(w1.get_l()))
    {
      throw przekroczenie_zakresu("przekroczenie zakresu");
    }
    if(w1.get_l() == 0)
    {
      throw dzielenie_przez_0("dzielenie przez 0");
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
      throw dzielenie_przez_0("dzielenie przez 0");
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
    return (double)this->licz/this->mian;
  }

  Wymierna::operator int() //operator jawnego rzutowania na typ int
  {
    return this->licz/this->mian;
  }

  ostream& operator << (ostream &wyjscie, const Wymierna &w)
  {
    int mian = w.mian;
    //mianownik rozklada się wylacznie na 2 lub 5
    while (mian % 2 == 0)
    {
      mian /= 2;
    }
    while (mian % 5 == 0)
    {
      mian /= 5;
    }

    if (mian == 1) //skonczone
    {
      return wyjscie << (double)w.licz/w.mian;
    }
    else //nieskonczone okresowe
    {
        int l = w.licz;
        int m = w.mian;

        int calosci = l / m;
        int reszta = l % m;
        
        wyjscie << calosci;

        l -= calosci * m;
        
        vector<pair<char, int>> stany;
        unsigned int pocz_powt = 0;

        while(reszta)
        {
            reszta *= 10;
            int r = reszta / m;
            char cyfra = r + '0';
            reszta = reszta - r * m;
            auto acc = make_pair(cyfra, reszta);
            stany.push_back(acc);

            for (unsigned int i = 0; i < stany.size() - 1; i++)
            {
                if (acc == stany[i])
                {
                    pocz_powt = i;
                    reszta = 0;
                    stany.pop_back();
                    break;
                }
            }
        }

        wyjscie << ".";
        unsigned int i = 0;

        for (auto& stan : stany)
        {
            if (i == pocz_powt)
            {
              wyjscie << "(";
            }
            wyjscie << stan.first;
            i++;
        }

        wyjscie << ")";
        return wyjscie;
    }
  }
}