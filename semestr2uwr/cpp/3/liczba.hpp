#include <iostream>
using namespace std;

static constexpr int l = 4;

class liczba {
    double* lista;
    int index;
    int rozmiar;
public:
    liczba();
    liczba(double x);
    liczba(const liczba& w);
    liczba(liczba &&w);

    ~liczba();

    liczba& operator=(const liczba &w);
    liczba& operator=(liczba &&w);

    void nowa(double x);
    void cofnij();
    void printl();
};
