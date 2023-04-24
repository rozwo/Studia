#include <bits/stdc++.h>
using namespace std;

enum operatorType
{
    DOD = 6,
    ODEJ = 5,
    MNOZ = 4,
    DZIEL = 3,
    MOD = 2,
    POT = 1
};

class Wyrazenie
{
public:

    virtual double oblicz() = 0;
    virtual string zapis() = 0;
    virtual int priorytet() = 0;
    virtual ~Wyrazenie() = default;
};

class Operator1arg : public Wyrazenie
{
protected:
    int priorytet() {return 0;};
    Wyrazenie* operand1;
    Operator1arg(Wyrazenie* wyr) : operand1(wyr) {};
public:
    virtual ~Operator1arg()
    {
        delete this->operand1;
    }
};

class Operator2arg : public Operator1arg
{
protected:
    Wyrazenie* operand2;
    Operator2arg(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator1arg(wyr1), operand2(wyr2) {};

public:
    virtual ~Operator2arg()
    {
        delete this->operand1;
        delete this->operand2;
    }
};
