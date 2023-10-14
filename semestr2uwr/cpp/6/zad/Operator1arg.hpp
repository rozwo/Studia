#include "Liczba.hpp"

class Sin : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Sin(Wyrazenie* wyr) : Operator1arg(wyr) {};

};

class Cos : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Cos(Wyrazenie* wyr) : Operator1arg(wyr) {};
};

class Exp : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Exp(Wyrazenie* wyr) : Operator1arg(wyr) {};
};

class Ln : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Ln(Wyrazenie* wyr) : Operator1arg(wyr) {};
};

class Bezwzgl : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Bezwzgl(Wyrazenie* wyr) : Operator1arg(wyr) {};
};

class Przeciwna : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Przeciwna(Wyrazenie* wyr) : Operator1arg(wyr) {};
};

class Odwrotna : public Operator1arg
{
public:
    double oblicz() override;
    string zapis() override;
    Odwrotna(Wyrazenie* wyr) : Operator1arg(wyr) {};
};
