#include "wymierna.hpp"

using namespace obliczenia;

int main()
{   
    try
    {
        Wymierna w1(1,3);
        cout << "1/3 = " << w1 << endl;
        Wymierna w2(1,4);
        Wymierna w3(6,5);
        Wymierna w4 = w2 + w3;
        cout << "1/4 + 6/5 = " << w4 << endl;
        w4 = w2 - w3;
        cout << "1/4 - 6/5 = " << w4 << endl;
        w4 = w2 * w3;
        cout << "1/4 * 6/5 = " << w4 << endl;
        w4 = w2 / w3;
        cout << "1/4 / 6/5 = " << w4 << endl;
        w4 = - w2;
        cout << "- 1/4 = " << w4 << endl;
        w4 = ! w3;
        cout << "! 6/5 = " << w4 << endl;
        Wymierna w5(8,1);
        cout << w5 << endl;
    }
    catch(dzielenie_przez_0 &error)
    {
        cerr << error.what();
    }
    catch(przekroczenie_zakresu &error)
    {
        cerr << error.what();
    }

    try
    {
        Wymierna w6(1,0);
        cout << w6 << endl;
    }
    catch(dzielenie_przez_0 &error)
    {
        cerr << error.what();
    }
    catch(przekroczenie_zakresu &error)
    {
        cerr << error.what();
    }

    try
    {
        Wymierna w9(1,9);
        cout << endl << w9 << endl;
    }
    catch(dzielenie_przez_0 &error)
    {
        cerr << error.what();
    }
    catch(przekroczenie_zakresu &error)
    {
        cerr << error.what();
    }

    try
    {
        Wymierna w7(INT_MAX,1);
        Wymierna w8(4,2);
        cout << w7 + w8 << endl;
    }
    catch(dzielenie_przez_0 &error)
    {
        cerr << error.what();
    }
    catch(przekroczenie_zakresu &error)
    {
        cerr << error.what();
    }

    try
    {
        Wymierna w10(2359348,99900);
        cout << endl << "2359348/99900" << w10 << endl;
    }
    catch(dzielenie_przez_0 &error)
    {
        cerr << error.what();
    }
    catch(przekroczenie_zakresu &error)
    {
        cerr << error.what();
    }
}
