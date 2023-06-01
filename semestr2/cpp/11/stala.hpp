#pragma once

#include "operand.hpp"
#include <string>
#include <map>
using namespace std;

namespace kalkulator {
    // klasa reprezentujaca stale wbudowane w program
    class stala : public operand {
        public:
            // kazdy obiekt stalej ma swoja nazwe (e, pi, fi)
            const string nazwa;
            // i wartosc
            const double wartosc;

            // metoda statyczna, ktorej zadaniem jest pobranie wartosci stalej
            // po jej nazwie
            static double pobierzStala(string nazwa);
            stala(string, double);
            virtual ~stala() {};
            // deklaracja implementacji metody pobierajacej wartosc
            double pobierzWartosc();

        private:
            // statyczna mapa, ktora zawiera wszystkie stale dostepne w kalkulatorze
            static map<string, double> mapaStalych;
    };
}

