#include "zmienna.hpp"
#include "stala.hpp"
#include "liczba.hpp"
#include "funkcja.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;


double wykonaj_print(string wyrazenie) {
    vector<shared_ptr<symbol>> wektor; // wektor inteligentnych wskaznikow do symboli napotkanych przy przechodzeniu przez wyrazenie
                                       // dzieki nim nie musismy martwic sie zwalnianiem pamieci
    int index = 0;
    int koniec;
    do {
        koniec = wyrazenie.find(' ', index); // koniec nastepnego symbolu (oddzielone spacjami)
        string znaki = wyrazenie.substr(index, koniec-index); //pobieram pierwszy symbol
        index += znaki.length() + 1; // ustawiamy index na poczatek kolejnego (ewentualnego) symbolu

        // jesli pierwszy element symbolu jest cyfra lub znak minus, to przyjmujemy ze to liczba
        if (isdigit(znaki.at(0)) || znaki.at(0) == '-' && znaki.length() > 1) { // jesli sa tam tez jakies litery, to przy rzutowaniu bedziemy mieli wyjatek
            double wartosc = stod(znaki); // stod - konwertuje sekwencję znaków na double
            shared_ptr<symbol> s;
            s.reset(new liczba(wartosc));
            wektor.push_back(s); // wrzucamy wartosc do wektora symboli
        } else { // wpp sprawdzamy czy jest to zmienna, stala lub funkcja
            bool znaleziono = false;
            try { // probujemy pobrac zmienna po jej nazwie - jesli nie to rzuca wyjatek i sprawdza dalej
                double wartosc = zmienna::pobierzZmienna(znaki);
                shared_ptr<symbol> s;
                s.reset(new zmienna(znaki));
                wektor.push_back(s);
                znaleziono = true;
            } catch (out_of_range) {}

            if (!znaleziono) { // jesli nie znalezlismy, to szukamy w stalych (tak samo)
                try {
                    double wartosc = stala::pobierzStala(znaki);
                    shared_ptr<symbol> s;
                    s.reset(new stala(znaki, wartosc));
                    wektor.push_back(s);
                    znaleziono = true;
                } catch (out_of_range) {}
            }

            if (!znaleziono) { // jak nadal nie, to moze to byc jeszcze funkcja
                try {
                    funkcja::rodzaj rodzajFunkcji = funkcja::pobierzFunkcje(znaki);
                    shared_ptr<symbol> s;
                    s.reset(new funkcja(rodzajFunkcji));
                    wektor.push_back(s);
                } catch (out_of_range) { // jesli nie jest to też funkcja, to znaczy ze jest blad
                    clog << "Nieznany symbol!" << endl;
                    throw std::invalid_argument("Blad w symbolu");
                }
            }
        }
    } while (koniec != -1); // koniec przyjmuje wartosc -1 gdy dojdzie do konca (nie bedzie wiecej symboli)

    // teraz gdy mamy symbole w wektorze, to po kolei wywolujemy na nich metode wykonaj()
    // symbole maja rozne implementacje tej metody wirtualnej
    for (auto it = wektor.begin(); it != wektor.end(); it++) {
        it->get()->wykonaj();
    }

    // teraz sprawdzamy ostateczna wartosc, ktora zostala na stosie (wpp zostanie rzucony wyjatek)
    double ostatecznyWynik = symbol::ostatecznyWynik();
    return ostatecznyWynik;
}

void wykonaj_set(string wyrazenie, string zmienna) {
    try {
        // wykonujemy najpierw print, bo ona zwraca wartosc wyrazenia, bo dzieki temu mozemy przypisac cale wyrazenie do zmiennej
        double wynik = wykonaj_print(wyrazenie);
        zmienna::dodajZmienna(zmienna, wynik);
    } catch (invalid_argument) {
        clog << "Niepoprawna nazwa zmiennej - nie moze zawierac slow kluczowych oraz powinna miec maksymalnie 7 znakow" << endl;
    }
}

void wykonaj_clear() {
    zmienna::wyczyscZmienne();
}

// metoda glowna
int main() {
    cout << "Kalkulator ONP" << endl;
    // petla w ktorej dziala kalkulator
    while (true) {
        cout << "Wprowadz komende" << endl;
        string komenda;
        getline(cin, komenda); // pobieramy komende od uzytkownika
        try {
            int podzial = komenda.find(' '); // gdzie jest pierwsza spacja
            string pierwszeSlowo = komenda.substr(0, podzial); // bierzemy wartosc komendy od lewej do spacji (pierwszej)
            if (pierwszeSlowo == "print") {
                if (podzial == -1) { // jesli podzial == -1 to oznacza ze jest tylko jedno slowo w komendzie, wiec jest ona nie kompletna
                    clog << "Niekompletna komenda!" << endl;
                    continue;
                }
                // wpp pobieramy reszte zdania i przekazujemy do funkcji ktora wykonuje print
                double wynik = wykonaj_print(komenda.substr(6, komenda.length()));
                cout << wynik << endl;
            } else if (pierwszeSlowo == "set") {
                if (podzial == -1) { // jesli podzial == -1 to oznacza ze jest tylko jedno slowo w komendzie, wiec jest ona nie kompletna
                    clog << "Niekompletna komenda!" << endl;
                    continue;
                }
                // wpp pobieramy reszte zdania
                string reszta = komenda.substr(4, komenda.length());
                podzial = reszta.find(" to ");
                if (podzial == -1) {
                    clog << "Niekompletna komenda! (brakuje 'to')" << endl;
                    continue;
                }
                string zmienna = reszta.substr(0, podzial);
                string wyrazenie = reszta.substr(podzial + 4, reszta.length());
                wykonaj_set(wyrazenie, zmienna);
                cout << "Przypisano" << endl;
            } else if (pierwszeSlowo == "clear") {
                wykonaj_clear();
                cout << "Wyczyszczono zmienne" << endl;
            } else if (pierwszeSlowo == "exit") {
                cout << "Koniec programu" << endl;
                break;
            } else { // jesli nie pasuje do komendy, to dajemy blad
                clog << "Nieprawidlowa komenda!" << endl;
            }
        }
        catch(...) {
            clog << "Blad w wyrazeniu!" << endl;
        }
    }
}
