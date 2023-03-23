#include "liczba.hpp"

int liczba::l = 4;

liczba::liczba() : liczba::liczba(0) { //konstruktor bezargumentowy

}

liczba::~liczba() { //destruktor
    delete[] lista;
    lista = new double[l]();
    rozmiar = 0;
}

liczba::liczba(double x) {
    lista = new double[l]();
    lista[0] = x;
    rozmiar = 1;
    index = 0;
}

liczba &liczba::operator=(const liczba &)= default;

liczba &liczba::operator=(liczba &&)= default;

liczba::liczba(const liczba &w) {
    lista = new double[l]();
    lista[0] = (w.lista)[w.index];
    rozmiar = 1;
    index = 0;
}

liczba::liczba(liczba &&w) {
    lista = w.lista;
    index = w.index;
    rozmiar = w.rozmiar;
    w.lista = new double[l]();
    w.rozmiar = 0;
}

void liczba::nowa(double x) {
    index += 1;
    index = index % l;
    rozmiar = min(rozmiar + 1, l);
    lista[index] = x;
}

void liczba::cofnij() {
    if(rozmiar == 1) return;
    rozmiar--;
    index = (l + index - 1)%l; //szybciej by dzialalo if przyp bo % jest dlugie
}

void liczba::printl() {
    if(rozmiar == 0)
    {
        cout << "nie ma historii";
    }
    else
    {
        for(int i = 0; i < min(rozmiar, l); i++)
        {
            cout << lista[(l + index - i)%l] << " ";
        }
    }
    cout << endl;
}

