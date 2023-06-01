#pragma once

#include "operand.hpp"
#include <bits/stdc++.h>
using namespace std;

namespace kalkulator
{
    // klasa reprezentujaca zmienne, ktore mozna dodawac, zmieniac i usuwac
    class zmienna : public operand
    {
        public:
            // nazwa zmiennej
            const string nazwa;

            // statyczna metoda, ktora pobiera wartosc zmiennej po jej nazwie
            static double pobierzZmienna(string);
            // metoda statyczna dodajaca zmienna do mapy zmiennych
            static void dodajZmienna(string, double);
            // metoda statyczna usuwajaca wszystkie zmienne
            static void wyczyscZmienne();
            zmienna(string);
            virtual ~zmienna() {};
            // deklaracja implementacji metody wirtualnej do pobierania wartosci z obiektu zmiennej
            double pobierzWartosc();

        private:
            // statyczna mapa zawierajaca wszystkie zmienne dostepne w programie
            static map<string, double> mapaZmiennych;
    };
}
