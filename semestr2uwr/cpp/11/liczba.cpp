#include "liczba.hpp"
#include <bits/stdc++.h>
using namespace kalkulator;

liczba::liczba(double wartosc) : wartosc(wartosc) {}  // konstruktor z lista inicjalizacyjna

double liczba::pobierzWartosc() {
    return this->wartosc;
}
