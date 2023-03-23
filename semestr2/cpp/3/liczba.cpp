#include "liczba.hpp"

int liczba::l = 4;

liczba::liczba() : liczba::liczba(0) { //konstruktor bezargumentowy

}

liczba::~liczba() { //destruktor
    if(lista != nullptr) delete[] lista;
}

liczba::liczba(double x) {
    lista = new double[l]();
    lista[0] = x;
    rozmiar = 1;
    index = 0;
}

liczba &liczba::operator=(const liczba &w) {
    if(this == &w) return *this;
    this->~liczba();
    lista = new double[l]();
    index = w.index;
    rozmiar = w.rozmiar;
    for(int i = 0; i < min(rozmiar, l); i++)
    {
        lista[(l + index - i)%l] = w.lista[(l + index - i)%l];
    }
    return *this;
}

liczba &liczba::operator=(liczba &&w) {
    if(this == &w) return *this;
    swap(lista, w.lista);
    swap(index, w.index);
    swap(rozmiar, w.rozmiar);
    return *this;
}

liczba::liczba(const liczba &w) {
    lista = new double[l]();
    lista[0] = (w.lista)[w.index];
    rozmiar = 1;
    index = 0;
}

liczba::liczba(liczba &&w) : liczba::liczba(0) {
    swap(lista, w.lista);
    swap(index, w.index);
    swap(rozmiar, w.rozmiar);
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

