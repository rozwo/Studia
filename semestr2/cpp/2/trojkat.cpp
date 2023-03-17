#include "globalne.hpp"

trojkat::trojkat(const punkt& a, const punkt& b, const punkt& c) {
    odcinek pom1 = odcinek (a,b);
    odcinek pom2 = odcinek (b,c);
    odcinek pom3 = odcinek (c,a);
    if (pom1.nalezy(c) ||
        pom2.nalezy(a) ||
        pom3.nalezy(b) ){
        throw invalid_argument("punkty sa wspolliniowe - nie mozna utworzyc trojkata");
    }
    d = a;
    e = b;
    f = c;
};

trojkat::trojkat(const trojkat &t) {
    d = t.d;
    e = t.e;
    f = t.f;
}

trojkat& trojkat::operator = (const trojkat& a) = default;

punkt trojkat::wez_punkt_d() {
    return d;
}

punkt trojkat::wez_punkt_e() {
    return e;
}

punkt trojkat::wez_punkt_f() {
    return f;
}

void trojkat::translacja(const wektor& a) {
    d.translacja(a);
    e.translacja(a);
    f.translacja(a);
}

void trojkat::obrot (double alpha, const punkt& b) {
    d.obrot(alpha,b);
    e.obrot(alpha,b);
    f.obrot(alpha,b);
}

void trojkat::sym_punkt(const punkt& b) {
    d.sym_punkt(b);
    e.sym_punkt(b);
    f.sym_punkt(b);
}

void trojkat::sym_os_x() {
    d.sym_os_x();
    e.sym_os_x();
    f.sym_os_x();
}

void trojkat::sym_os_y() {
    d.sym_os_y();
    e.sym_os_y();
    f.sym_os_y();
}

//obwód trójkąta
double trojkat::obwod() {
    return odleglosc(this->d, this->e) +
           odleglosc(this->e, this->f) +
           odleglosc(this->f, this->d);
}

//pole trójkąta
double trojkat::pole() {
    double pom = (this->obwod()/2);
    return sqrt(pom*(pom - odleglosc(this->d, this->e)) *
                    (pom - odleglosc(this->e, this->f)) *
                    (pom - odleglosc(this->f, this->d)));
}

//funkcję składową sprawdzającą, czy zadany punkt leży wewnątrz trójkąta
bool trojkat::nalezy(const punkt& c) {
    double pom1 = strona(this->d, this->e, c);
    double pom2 = strona(this->e, this->f, c);
    double pom3 = strona(this->f, this->d, c);
    return ((pom1 >= 0 && pom2 >= 0 && pom3 >= 0) ||
            (pom1 <= 0 && pom2 <= 0 && pom3 <= 0));
}
