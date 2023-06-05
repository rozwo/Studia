#include "zmienna.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;

map<string, double> zmienna::mapaZmiennych;

vector<string> wyjatki = { // wektor zawierajacy slowa niedozwolone jako nazwy zmiennych
    "print",
    "set",
    "clear",
    "exit"
};

zmienna::zmienna(string nazwa) : nazwa(nazwa) {} // konstruktor z lista inicjalizacyjna


double zmienna::pobierzZmienna(string nazwa) {
    return zmienna::mapaZmiennych.at(nazwa);
}

void zmienna::dodajZmienna(string nazwa, double wartosc) {
    // szukamy czy nazwa nie jest niedozwolona
    if (find(wyjatki.begin(), wyjatki.end(), nazwa) != wyjatki.end() || nazwa.length() > 7) {
        throw invalid_argument("Niepoprawna nazwa zmiennej");
    }
    // przypisujemy do mapy - jesli taka zmienna istnieje, to zostanie nadpisana
    zmienna::mapaZmiennych[nazwa] = wartosc;
}

void zmienna::wyczyscZmienne() {
    zmienna::mapaZmiennych.clear();
}

double zmienna::pobierzWartosc() {
    return zmienna::mapaZmiennych[this->nazwa];
}
