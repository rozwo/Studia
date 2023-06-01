#include "zmienna.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;

// deklarujemy uzycie mapy zmiennych
map<string, double> zmienna::mapaZmiennych;

// wektor zawierajacy slowa niedozwolone jako nazwy zmiennych
vector<string> wyjatki = {
    "print",
    "assign",
    "clear",
    "exit",
    "to"
};

// konstruktor z lista inicjalizacyjna
zmienna::zmienna(string nazwa) : nazwa(nazwa) {}


// pobieranie zmiennej po nazwie (metoda statyczna)
double zmienna::pobierzZmienna(string nazwa)
{
    return zmienna::mapaZmiennych.at(nazwa);
}

// metoda statyczna dodajaca zmienna o danej nazwie
void zmienna::dodajZmienna(string nazwa, double wartosc)
{
    // szukamy czy nazwa nie jest niedozwolona
    if (find(wyjatki.begin(), wyjatki.end(), nazwa) != wyjatki.end() || nazwa.length() > 7)
    {
        throw invalid_argument("Niepoprawna nazwa zmiennej");
    }
    // przypisujemy do mapy - jesli taka zmienna juz istnieje, to zostanie ona nadpisana
    zmienna::mapaZmiennych[nazwa] = wartosc;
}

void zmienna::wyczyscZmienne()
{
    zmienna::mapaZmiennych.clear();
}

// pobieranie zmiennej z obiektu - szukamy w mapie zmiennych po nazwie danej zmiennej
double zmienna::pobierzWartosc()
{
    return zmienna::mapaZmiennych[this->nazwa];
}
