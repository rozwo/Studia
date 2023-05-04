#include "wymierna.hpp"

using namespace obliczenia;

int main()
{
//   try
//   {
    Wymierna w1(1,3);
    cout << "1/3 = " << w1 << endl;
    Wymierna w2(1,4);
    Wymierna w3(6,7);
    Wymierna w4 = w2 + w3;
    cout << "1/4 + 6/7 = " << w4 << endl;
    w4 = w2 - w3;
    cout << "1/4 - 6/7 = " << w4 << endl;
    w4 = w2 * w3;
    cout << "1/4 * 6/7 = " << w4 << endl;
    w4 = w2 / w3;
    cout << "1/4 / 6/7 = " << w4 << endl;
    w4 = - w2;
    cout << "- 1/4 = " << w4 << endl;
    w4 = ! w3;
    cout << "odwrotnosc 6/7 = " << w4 << endl;
    Wymierna w5(8,1);
    cout << w5 << endl;
    // Wymierna w6(1,0);
//   }

//   catch(dzielenie_przez_0 &error)
//   {
//     cerr << error.what();
//   }

//   catch(przekroczenie_zakresu &error)
//   {
//     cerr << error.what();
//   }
}