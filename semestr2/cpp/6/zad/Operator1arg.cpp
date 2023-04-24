#include "Operator1arg.hpp"

double Sin::oblicz() {
    return sin(this->operand1->oblicz());
}

string Sin::zapis() {
    return "sin(" + this->operand1->zapis() + ")";
}

double Cos::oblicz() {
    return cos(this->operand1->oblicz());
}

string Cos::zapis() {
    return "cos(" + this->operand1->zapis() + ")";
}

double Exp::oblicz() {
    return exp(this->operand1->oblicz());
}

string Exp::zapis() {
    return "exp(" + this->operand1->zapis() + ")";
}

double Ln::oblicz() {
    return log(this->operand1->oblicz());
}

string Ln::zapis() {
    return "ln(" + this->operand1->zapis() + ")";
}

double Bezwzgl::oblicz() {
    double liczba = this->operand1->oblicz();
    if(liczba < 0)
    {
        return -1 * liczba;
    }
    else
    {
        return liczba;
    }
}

string Bezwzgl::zapis() {
    return "|" + this->operand1->zapis() + "|";
}

double Przeciwna::oblicz() {
    return -1 * this->operand1->oblicz();
}

string Przeciwna::zapis() {
    if(this->operand1->priorytet() > 0)
        return "-(" + this->operand1->zapis() + ")";
    else
        return "-" + this->operand1->zapis();
}

double Odwrotna::oblicz() {
    double liczba = this->operand1->oblicz();
    if(liczba == 0)
    {
        throw std::invalid_argument("Dzielenie przez zero! (odwrotna)");
    }
    else
    {
        return 1 / liczba;
    }
}

string Odwrotna::zapis() {
    if (this->operand1->priorytet() > 0)
    {
        return "1/(" + this->operand1->zapis() + ")";
    }
    else
    {
        return "1/" + this->operand1->zapis();
    }
}
