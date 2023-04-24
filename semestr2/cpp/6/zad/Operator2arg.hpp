#include"Operator1arg.hpp"

class Dod : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Dod(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};
};

class Odej : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Odej(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};  
};

class Mnoz : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Mnoz(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};
};

class Dziel : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Dziel(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};
};

class Mod : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Mod(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};
};

class Log : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Log(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};
};

class Pot : public Operator2arg
{
public:
    double oblicz() override;
    string zapis() override;
    int priorytet();
    Pot(Wyrazenie* wyr1, Wyrazenie* wyr2) : Operator2arg(wyr1, wyr2) {};
};
