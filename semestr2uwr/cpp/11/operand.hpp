#pragma once
#include "symbol.hpp"

// operandy = liczby, stale, zmienne
namespace kalkulator {
    class operand : public symbol {
        public:
            operand() {};
            virtual ~operand() {};
            // metoda wirtualna
            virtual double pobierzWartosc() = 0;
            // deklarujemy implementacje metody wirtualnej z klasy symbol
            void wykonaj() {
                symbol::stos.push(this); // przy napotkaniu operanda wrzucamy go na stos
            };
    };
}
