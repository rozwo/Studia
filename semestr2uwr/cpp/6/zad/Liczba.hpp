#include "Zmienna.hpp"

class Liczba : public Wyrazenie
{
    double val;
public:
    Liczba(double x) : val(x) {};
    double oblicz() override;
    string zapis() override;
    int priorytet() {return 0;};
    virtual ~Liczba() = default;
};