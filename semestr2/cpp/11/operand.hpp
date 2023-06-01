#pragma once

#include "symbol.hpp"

namespace kalkulator {
    // klasa abstrakcyjna, ktora okresla operandy (liczby, stale, zmienne)
    class operand : public symbol {
        public:
            operand() {};
            virtual ~operand() {};
            // metoda czysto wirtualna, ktora ma za zadanie pobrac wartosc z operandu,
            // dzieki temu mozemy traktowac operandy ta metoda i otrzymac wlasciwa wartosc
            // niezaleznie czy mamy do czynienia z liczba, zmienna czy stala
            virtual double pobierzWartosc() = 0;
            // deklarujemy implementacje metody wirtualnej wykonaj() z klasy symbol.
            void wykonaj() { // dla kazdego operanda zasada dzialania jest taka sama - po prostu przy napotkaniu operanda wrzucamy go na stos
                symbol::stos.push(this);
            };
    };
}
