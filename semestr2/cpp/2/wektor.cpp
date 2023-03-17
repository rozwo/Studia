#include "globalne.hpp"

wektor::wektor() {
    a = b = 0;
}

wektor::wektor(double x, double y) {
    this->a = x;
    this->b = y;
}

double wektor::wsp_a() {
    return a;
}

double wektor::wsp_b() {
    return b;
}

