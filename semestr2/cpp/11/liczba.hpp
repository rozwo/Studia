#pragma once

#include "operand.hpp"

namespace kalkulator {
    // klasa okreslajaca zwykla liczbe w dzialaniu
    class liczba : public operand {
        public:
            const double wartosc;
            liczba(double wartosc);
            virtual ~liczba() {};
            // deklaracja implementacji metody wirtualnej z klasy operand
            double pobierzWartosc();
    };
}
