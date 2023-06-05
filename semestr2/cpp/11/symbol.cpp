#include "symbol.hpp"
#include "liczba.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;


// funkcja okreslajaca ostateczny wynik (ostatni (jedyny) element na stosie)
double symbol::ostatecznyWynik() {
    // jesli ostatecznie na stosie jest mniej lub wiecej elementow niz jeden,
    // tzn ze dzialanie bylo niepoprawne - wyjatek
    if (symbol::stos.size() != 1) {
        throw invalid_argument("Brak dzialania");
    }
    // rzutujemy symbol na liczbe
    double wynik = static_cast<liczba*>(symbol::stos.top())->pobierzWartosc();
    stos.pop();
    return wynik;
}
