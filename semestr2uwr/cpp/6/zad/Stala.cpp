#include "Stala.hpp"

pi::pi() {
    val = M_PI;
}

double pi::oblicz() {
    return val;
}

string pi::zapis() {
    return "pi";
}

e::e() {
    val = M_E;
}

double e::oblicz() {
    return val;
}

string e::zapis() {
    return "e";
}

fi::fi() {
    //zloty podzial
    val = 1.6180339887;
}

double fi::oblicz() {
    return val;
}

string fi::zapis() {
    return "fi";
}
