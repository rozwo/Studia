#include "Stala.hpp"

class Zmienna : public Wyrazenie
{
    static vector<pair<string,double>> zmienne;
    string symbol;
public:
    Zmienna(string symbol) : symbol(symbol) {};
    double oblicz() override;
    string zapis() override;
    int priorytet() {return 0;};
    virtual ~Zmienna() = default;
    static double wez_wart(string symbol);
    static bool czy_istnieje(string symbol);
    static void dod_zmienna(string symbol, double wartosc);
    static void zmien_nazwe_zmiennej(string stara_nazwa, string nowa_nazwa);
    static void zmien_wart(string symbol, double nowa_wartosc);
    static void usun_zmienna(string symbol);
};