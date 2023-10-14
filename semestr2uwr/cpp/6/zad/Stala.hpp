#include "Wyrazenie.hpp"

class Stala : public Wyrazenie {
protected:
    double val;
public:
    int priorytet() {return 0;};
};

class pi final : public Stala {
public:
    pi();
    double oblicz() override;
    string zapis() override;
};

class e final : public Stala {
public:
    e();
    double oblicz() override;
    string zapis() override;
};

class fi final : public Stala {
public:
    fi();
    double oblicz() override;
    string zapis() override;
};
