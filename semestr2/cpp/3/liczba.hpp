#include <iostream>
using namespace std;

class liczba {
    private:
        static int l;
        double* lista;
        int index;
        int rozmiar;
    public:
        liczba();
        ~liczba();
        liczba(double x);
        liczba& operator=(const liczba &w);
        liczba& operator=(liczba &&w);
        liczba(const liczba& w);
        liczba(liczba &&w);
        void nowa(double x);
        void cofnij();
        void printl();
};
