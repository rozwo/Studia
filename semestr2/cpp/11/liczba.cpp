#include "liczba.hpp"
#include <bits/stdc++.h>
using namespace kalkulator;

// konstruktor z lista inicjalizacyjna
liczba::liczba(double wartosc) : wartosc(wartosc) {}

// dla tej klasy pobranie wartosci to po prostu zwrocenie tej, ktora zawiera
double liczba::pobierzWartosc() {
    return this->wartosc;
}
