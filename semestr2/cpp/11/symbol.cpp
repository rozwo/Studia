#include "symbol.hpp"
#include "liczba.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;


// funkcja okreslajaca ostateczny wynik, czyli ostatni (jedyny) element na stosie
double symbol::ostatecznyWynik() {
    // Jesli po wykonaniu wszystkich operacji jest mniej lub wiecej elementow niz jeden,
    // to znaczy ze dzialanie bylo niepoprawne - rzucamy wyjatek
    if (symbol::stos.size() != 1) {
        throw invalid_argument("Brak dzialania");
    }
    // Rzutujemy ten symbol na liczbe. Jesli nie jest to liczba, to rzucony zostanie wyjatek
    double wynik = static_cast<liczba*>(symbol::stos.top())->pobierzWartosc();
    // usuwamy ten element i zwracamy wynik
    stos.pop();
    return wynik;
}
