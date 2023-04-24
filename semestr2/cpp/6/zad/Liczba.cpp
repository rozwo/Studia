#include "Liczba.hpp"

double Liczba::oblicz() {
    return this->val;
}

string Liczba::zapis() {
    return to_string(this->val);
}
