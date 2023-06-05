#pragma once
#include "operand.hpp"
#include <bits/stdc++.h>
using namespace std;

namespace kalkulator {
    class zmienna : public operand {
        public:
            const string nazwa;

            static double pobierzZmienna(string);
            static void dodajZmienna(string, double);
            static void wyczyscZmienne();
            zmienna(string);
            virtual ~zmienna() {};
            double pobierzWartosc();

        private:
            static map<string, double> mapaZmiennych;
    };
}
