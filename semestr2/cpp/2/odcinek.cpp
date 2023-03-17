#include "globalne.hpp"

odcinek::odcinek(punkt a, punkt b) {
    if (a.wsp_x() == b.wsp_x() &&
        a.wsp_y() == b.wsp_y()) {
        throw invalid_argument("odcinka o dlugosci 0 nie istnieje");
    }
    i = a;
    j = b;
}

odcinek::odcinek(const odcinek &t) {
    i = t.i;
    j = t.j;
}

punkt odcinek::wez_punkt_i() {
    return i;
}

punkt odcinek::wez_punkt_j() {
    return j;
}

odcinek& odcinek::operator=(const odcinek& a)= default;

void odcinek::translacja(const wektor& a) {
    i.translacja(a);
    j.translacja(a);
}

void odcinek::obrot (double alpha, const punkt& b) {
    i.obrot(alpha,b);
    j.obrot(alpha,b);
}

void odcinek::sym_punkt(const punkt& b) {
    i.sym_punkt(b);
    j.sym_punkt(b);
}

void odcinek::sym_os_x() {
    i.sym_os_x();
    j.sym_os_x();
}

void odcinek::sym_os_y() {
    i.sym_os_y();
    j.sym_os_y();
}

//długość odcinka
double odcinek::dlugosc() {
    return odleglosc(this->i, this->j);
}

//funkcję składową sprawdzającą, czy zadany punkt należy do odcinka.
bool odcinek::nalezy(punkt a) {
    return (a.wsp_x() >= min(i.wsp_x(), j.wsp_x()) &&
            a.wsp_x() <= max(i.wsp_x(), j.wsp_x()) &&
            a.wsp_y() >= min(i.wsp_y(), j.wsp_y()) &&
            a.wsp_y() <= max(i.wsp_y(), j.wsp_y()) &&
            ((((a.wsp_y() - i.wsp_y()) * (j.wsp_x() - i.wsp_x()))
            - ((j.wsp_y() - i.wsp_y()) * (a.wsp_x() - i.wsp_x()))) == 0));

}
