#include "globalne.hpp"

//Ponadto zdefiniuj funkcję globalną, która będzie wyznaczać odległość pomiędzy parą punktów.
double odleglosc (punkt &p, punkt &r) {
    double dx = p.wsp_x() - r.wsp_x();
    double dy = p.wsp_y() - r.wsp_y();
    return sqrt(dx * dx + dy * dy);
}

//Dodatkowo zdefiniuj dwie funkcje globalne, które będą sprawdzać
//czy dwa odcinki są równoległe
bool rownolegle(odcinek c, odcinek d) {
    //proste pionowe
    if (c.wez_punkt_i().wsp_x() == c.wez_punkt_j().wsp_x() &&
        d.wez_punkt_i().wsp_x() == d.wez_punkt_j().wsp_x()) {
        return true;
    }
    //prosta pionowa i nie pionowa
    if (c.wez_punkt_i().wsp_x() == c.wez_punkt_j().wsp_x() ||
        d.wez_punkt_i().wsp_x() == d.wez_punkt_j().wsp_x()) {
            return false;
    }
    
    // postac kierunkowa
    double a = (c.wez_punkt_i().wsp_y() - c.wez_punkt_j().wsp_y()) /
               (c.wez_punkt_i().wsp_x() - c.wez_punkt_j().wsp_x());
    double b = (d.wez_punkt_i().wsp_y() - d.wez_punkt_j().wsp_y()) /
               (d.wez_punkt_i().wsp_x() - d.wez_punkt_j().wsp_x());
    return a == b;
}

//czy są prostopadłe
bool prostopadle(odcinek c, odcinek d) {
    //proste pionowe
    if (c.wez_punkt_i().wsp_x() == c.wez_punkt_j().wsp_x() &&
        d.wez_punkt_i().wsp_x() == d.wez_punkt_j().wsp_x()) {
            return false;
    }

    if (c.wez_punkt_i().wsp_x() == c.wez_punkt_j().wsp_x() &&
        d.wez_punkt_i().wsp_y() == d.wez_punkt_j().wsp_y() ||
        c.wez_punkt_i().wsp_y() == c.wez_punkt_j().wsp_y() &&
        d.wez_punkt_i().wsp_x() == d.wez_punkt_j().wsp_x()) {
        return true;
    }

    if ((c.wez_punkt_i().wsp_x() - c.wez_punkt_j().wsp_x()) == 0 ||
        (d.wez_punkt_i().wsp_x() - d.wez_punkt_j().wsp_x()) == 0){
        return false;
    }

    double a = (c.wez_punkt_i().wsp_y() - c.wez_punkt_j().wsp_y()) /
               (c.wez_punkt_i().wsp_x() - c.wez_punkt_j().wsp_x());
    double b = (d.wez_punkt_i().wsp_y() - d.wez_punkt_j().wsp_y()) /
               (d.wez_punkt_i().wsp_x() - d.wez_punkt_j().wsp_x());
    return a == (-1 / b);
}

//liczy czy c jest po prawej czy lewej od odcinka a b
double strona (punkt a, punkt b, punkt c) {
    return ((b.wsp_x() - a.wsp_x()) * (c.wsp_y() - a.wsp_y())
          - (b.wsp_y() - a.wsp_y()) * (c.wsp_x() - a.wsp_x()));
}

//Dodatkowo zdefiniuj dwie funkcje globalne, które będą sprawdzać
//czy dwa trójkąty są rozłączne
bool rozlaczne (trojkat a, trojkat b) {
    return (!a.nalezy(b.wez_punkt_d()) &&
            !a.nalezy(b.wez_punkt_e()) &&
            !a.nalezy(b.wez_punkt_f()) &&
            !b.nalezy(a.wez_punkt_d()) &&
            !b.nalezy(a.wez_punkt_e()) &&
            !b.nalezy(a.wez_punkt_f()));
}

//czy jeden zawiera się w drugim
bool zawiera (trojkat a, trojkat b) {
    return (a.nalezy(b.wez_punkt_d()) &&
            a.nalezy(b.wez_punkt_e()) &&
            a.nalezy(b.wez_punkt_f()));
}
