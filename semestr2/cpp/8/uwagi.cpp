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