#include "stala.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;

// mapa zawierajaca stale
map<string, double> stala::mapaStalych = {
            {"e", 2.718281828459},
            {"pi", 3.141592653589},
            {"fi", 1.618033988750}
        };

// konstruktor z lista inicjalizacyjna
stala::stala(string nazwa, double wartosc) : wartosc(wartosc), nazwa(nazwa) {}

// ta metoda statyczna pobiera z mapy stalych wartosc dla danej nazwy
double stala::pobierzStala(string nazwa) {
    return stala::mapaStalych.at(nazwa);
}

double stala::pobierzWartosc() {
    return this->wartosc;
}
