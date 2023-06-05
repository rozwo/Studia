#pragma once
#include "operand.hpp"

namespace kalkulator {
    class liczba : public operand {
        public:
            const double wartosc;
            liczba(double wartosc);
            virtual ~liczba() {};
            // deklaracja implementacji metody wirtualnej z klasy operand
            double pobierzWartosc();
    };
}
