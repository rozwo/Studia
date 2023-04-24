#include"Zmienna.hpp"

vector<pair<string,double>> Zmienna::zmienne;

double Zmienna::oblicz() {
    return wez_wart(this->symbol);
}

string Zmienna::zapis() {
    return this->symbol;
}

double Zmienna::wez_wart(string symbol) {
    for (auto& var : zmienne) //po kolei sprawdza kazda pare ze zmiennych
    {
        if (var.first == symbol)
        {
            return var.second;
        }
    }
    throw invalid_argument(symbol + " nie istnieje!");
}

bool Zmienna::czy_istnieje(string symbol) {
    for (auto& var : zmienne)
    {
        if (symbol == var.first)
        {
            return true;
        }
    }
    return false;
}

void Zmienna::dod_zmienna(string symbol, double wartosc)
{
    if (czy_istnieje(symbol))
    {
        for (auto& var : zmienne)
        {
            if (symbol == var.first)
            {
                var.second = wartosc;
                return;
            }
        }
    }
    else
    {
        zmienne.push_back({symbol, wartosc});
        return;
    }
}

void Zmienna::zmien_wart(string symbol, double nowa_wartosc)
{
    for (auto& var : zmienne)
    {
        if (symbol == var.first)
        {
            var.second = nowa_wartosc;
            return;
        }
    }
    throw invalid_argument(symbol + " nie istnieje! (zmien wart)");
}

void Zmienna::zmien_nazwe_zmiennej(string stara_nazwa, string nowa_nazwa)
{
    bool istnieje = false;
    for (auto& var : zmienne)
    {
        if (stara_nazwa == var.first)
        {
            var.first = nowa_nazwa;
            istnieje = true;
        }
    }
    if (!istnieje)
    {
        throw invalid_argument(stara_nazwa + " nie istnieje! (zmien nazwe)");
    }
}
void Zmienna::usun_zmienna(string symbol)
{
    int dl = Zmienna::zmienne.size();
    for (int i = 0; i < dl; i++)
    {
        if (Zmienna::zmienne[i].first == symbol)
        {
            Zmienna::zmienne.erase(Zmienna::zmienne.begin() + i); //erase - usuwa z wektora
            return;
        }
    }
    throw invalid_argument(symbol + " nie istnieje! (usun zmienna))");
}