#include "globalne.hpp"

punkt::punkt() { //konstruktor bezargumentowy
    x = y = 0;
}

punkt::punkt(double a, double b) {
    this->x = a;
    this->y = b;
}

punkt::~punkt() { //destruktor
    x = y = 0;
}

double punkt::wsp_x() {
    return x;
}

double punkt::wsp_y() {
    return y;
}

punkt::punkt(const punkt &t) {
    x = t.x;
    y = t.y;
}

punkt& punkt::operator=(const punkt& a)= default;

void punkt::translacja(wektor a) {
    x += a.wsp_a();
    y += a.wsp_b();
}

//obrot o kat (obrót wokół ustalonego punktu (b) wszystkich punktów płaszczyzny o zadany kąt (alpha))
void punkt::obrot(double alpha, const punkt& b) {
    double pomx = this->x - b.x;
    double pomy = this->y - b.y;
                        //zmieniam st na radiany
    this->x = (pomx * cos(alpha * pi / 180)) -
              (pomy * sin(alpha * pi / 180));
    this->y = (pomy * cos(alpha * pi / 180)) +
              (pomx * sin(alpha * pi / 180));
    this->x += b.x;
    this->y += b.y;
}

void punkt::sym_punkt(const punkt& b)
{
    this->obrot(180,b);
}

void punkt::sym_os_x() {
    this->y = - this->y;
}

void punkt::sym_os_y() {
    this->x = - this->x;
}