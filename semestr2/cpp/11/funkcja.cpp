#include "symbol.hpp"
#include "funkcja.hpp"
#include "operand.hpp"
#include "liczba.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace kalkulator;

#define PI 3.1415926535897 // definiujemy PI, potrzebne do niektorych funkcji

stack<symbol*> symbol::stos; // statyczny stosu z klasy symbol

map<string, funkcja::rodzaj> funkcja::mapaFunkcji = {
    {"+", f_add},
    {"-", f_sub},
    {"*", f_mul},
    {"/", f_div},
    {"%", f_modulo},
    {"min", f_min},
    {"max", f_max},
    {"log", f_log},
    {"pow", f_pow},
    {"abs", f_abs},
    {"sgn", f_sgn},
    {"floor", f_floor},
    {"ceil", f_ceil},
    {"frac", f_frac},
    {"sin", f_sin},
    {"cos", f_cos},
    {"atan", f_atan},
    {"acot", f_acot},
    {"ln", f_ln},
    {"exp", f_exp}
};

funkcja::funkcja(rodzaj dzialanie) : dzialanie(dzialanie) {} // konstruktor z lista inicjalizacyjna

funkcja::rodzaj funkcja::pobierzFunkcje(string nazwa) {
    return funkcja::mapaFunkcji.at(nazwa);
}

// funkcja pomocnicza dla jedno arg
double funkcja::pom1arg() {
    operand* pierwszy = static_cast<operand*>(symbol::stos.top()); // pobiera wartosc ze stosu
    symbol::stos.pop();
    return pierwszy->pobierzWartosc();
}

// funkcja pomocnicza dla dwu arg (zwraca pobrane wartosci jako pare)
pair<double, double> funkcja::pom2arg() {
    operand* pierwszy = static_cast<operand*>(symbol::stos.top());
    symbol::stos.pop();
    operand* drugi = static_cast<operand*>(symbol::stos.top());
    symbol::stos.pop();
    return pair<double, double>(pierwszy->pobierzWartosc(), drugi->pobierzWartosc());
}

void funkcja::wykonaj() {
    pair<double, double> wartosci;
    double wartosc;
    double wynik;
    // wykonujemy dzialanie w zaleznosci od jego typu
    switch(this->dzialanie) {
        case f_add:
            wartosci = pom2arg();
            wynik = wartosci.first + wartosci.second;
            symbol::stos.push(new liczba(wynik)); // wrzucamy na stos wynik
            break;
        case f_sub:
            wartosci = pom2arg();
            wynik = wartosci.first - wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_mul:
            wartosci = pom2arg();
            wynik = wartosci.first * wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_div:
            wartosci = pom2arg();
            if (wartosci.second == 0)
                throw overflow_error("dzielenie przez zero");
            wynik = wartosci.first / wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_modulo:
            wartosci = pom2arg();
            wynik = fmod(wartosci.first, wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_min:
            wartosci = pom2arg();
            wynik = min(wartosci.first, wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_max:
            wartosci = pom2arg();
            wynik = max(wartosci.first, wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_log:
            wartosci = pom2arg();
            wynik = log(wartosci.first)/log(wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_pow:
            wartosci = pom2arg();
            wynik = pow(wartosci.first, wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_abs:
            wartosc = pom1arg();
            wynik = abs(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_sgn:
            wartosc = pom1arg();
            wynik = wartosc > 0 ? 1 : -1;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_floor:
            wartosc = pom1arg();
            wynik = floor(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_ceil:
            wartosc = pom1arg();
            wynik = ceil(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_frac: //czesc ulamkowa
            wartosc = pom1arg();
            wynik = wartosc - trunc(wartosc);
            wynik = wynik > 0 ? wynik : -wynik;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_sin:
            wartosc = pom1arg();
            wynik = sin(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_cos:
            wartosc = pom1arg();
            wynik = cos(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_atan:
            wartosc = pom1arg();
            wynik = atan(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_acot:
            wartosc = pom1arg();
            wynik = PI/2 - atan(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_ln:
            wartosc = pom1arg();
            wynik = log(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_exp:
            wartosc = pom1arg();
            wynik = exp(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        default:
            // w razie gdyby nazwa nie pasowala do zadnego dzialania
            throw invalid_argument("Brak dzialania");
    }
}
