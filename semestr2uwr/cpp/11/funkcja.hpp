#pragma once
#include "symbol.hpp"
#include <bits/stdc++.h>
using namespace std;

namespace kalkulator {
    class funkcja : public symbol {
        public:
            enum rodzaj { //typ wyliczeniowy (dziala jak int tylko mamy wygodne nazwy)
      // dodane f_ przed nazwa bo niektore nazwy zachodzily na te uzywane w bibliotece
                f_add = 0,
                f_sub = 1,
                f_mul = 2,
                f_div = 3,
                f_modulo = 4,
                f_min = 5,
                f_max = 6,
                f_log = 7,
                f_pow = 8,
                f_abs = 9,
                f_sgn = 10,
                f_floor = 11,
                f_ceil = 12,
                f_frac = 13,
                f_sin = 14,
                f_cos = 15,
                f_atan = 16,
                f_acot = 17,
                f_ln = 18,
                f_exp = 19
            };

            // deklarujemy zmienna typu powyzszego enuma, bedzie to rodzaj naszej funkcji
            funkcja::rodzaj dzialanie;

            // funkcja statyczna pobierajaca funkcje po jej symbolu
            static funkcja::rodzaj pobierzFunkcje(string);
            funkcja(rodzaj);
            virtual ~funkcja() {};
            void wykonaj(); // metodo wirtualna

        private:
            // metody pomocnicze dla funkcji jedno- i dwuargumentowych
            pair<double, double> pom2arg();
            double pom1arg();
            // mapa zawierajaca funkcje przypisane ich symbolom
            static map<string, rodzaj> mapaFunkcji;
    };
}

