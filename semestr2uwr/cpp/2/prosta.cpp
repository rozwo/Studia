#include "globalne.hpp"

//mx + ny + l = 0

prosta::prosta() {
    m = n = l = 0;
}

prosta::prosta(double x, double y , double z) {
    this->m = x;
    this->n = y;
    this->l = z;
}

double prosta::wez_m() {
    return m;
}

double prosta::wez_n() {
    return n;
}

double prosta::wez_l() {
    return l;
}
