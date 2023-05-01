// int Wymierna::NWW(int a, int b) //najm wsp wiel
// {
//   int c = NWD(a,b);
//   return a/c * b;
// }

// int Wymierna::Skroc(int64_t a, int64_t b)
// {
//   if(a < 0)
//     a = -a;
//   while(a!=b)
//   {
//     if(a>b)
//     a-=b;
//     else: licz(x), mian(1) 
//       b-=a;
//   }
//   if(a > INT_MAX)
//     throw PrzekroczonoZakres("Przekroczono zakres inta");
//   return a;
// }

//operatory

// Wymierna & Wymierna::operator + (const Wymierna & w1)
// {
//   int64_t r = NWW(this->mian,w1.get_m());
//   int64_t l = this->licz * (r/this->mian) + w1.get_l() * (r/w1.get_m());
//   int x = Skroc(l,r);
//   if(r/x > INT_MAX || l/x > INT_MAX)
//     throw PrzekroczonoZakres("Przekroczono zakres inta");
//   int li = l/x;
//   int mi = r/x;
//   Wymierna w2(li,mi);
//   return w2;
// }

// Wymierna & Wymierna::operator - (const Wymierna & w1)
// {
//   int64_t r = NWW(this->mian,w1.get_m());
//   int64_t l = this->licz * (r/this->mian) - w1.get_l() * (r/w1.get_m());
//   int x = Skroc(l,r);
//   if(r/x > INT_MAX || l/x > INT_MAX)
//     throw PrzekroczonoZakres("Przekroczono zakres inta");
//   int li = l/x;
//   int mi = r/x;
//   Wymierna w2(li,mi);
//   return w2;
// }


//wyjatki

// NieDzielPrzezZero::NieDzielPrzezZero(const char* t)
// {
//   tresc = t;
// }

// const char* NieDzielPrzezZero::what()
// {
//   return tresc.c_str();
// }

// PrzekroczonoZakres::PrzekroczonoZakres(const char* t)
// {
//   tresc = t;
// }

// const char* PrzekroczonoZakres::what()
// {
//   return tresc.c_str();
// }



// operator strumieniowy ale XDDDDDDDDDDDDD co tu sie dzieje?!!!!

// namespace obliczenia
// {
//   int suma25(int a)
//   {
//     int w = 0;
//     while(a % 2 == 0)
//     {
//       a /= 2;
//       w++;
//     }
//     while(a % 5 == 0)
//     {
//       a /= 5;
//       w++;
//     }
//     return w;
//   }
//   ostream & operator << (ostream & wy, const Wymierna & x)
//   {
//     if(x.get_l()/x.get_m() == 0 && x.get_l() < 0)
//       wy << "-";
//     wy << x.get_l()/x.get_m();
//     if(x.get_l() % x.get_m() != 0)
//     {
//       wy << ".";
//       int suma = suma25(x.get_m());
//       int o = x.get_l() % x.get_m() * 10;
//       for(int i=0; i<suma ; i++)
//       {
//         wy << abs(o / x.get_m());
//         o = o % x.get_m() * 10;
//       }
//       wy << "(";
//       int p = o , i = 1;
//       while(p != o || i == 1)
//       {
//         wy << abs(o / x.get_m());
//         o = o % x.get_m() * 10;
//         i++;
//       }
//       wy << ")";
//     }
//     return wy;
//   }
// }