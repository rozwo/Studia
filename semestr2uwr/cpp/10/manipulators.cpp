#include "manipulators.hpp"
using namespace std;

// zdefiniuj własny manipulator bezparametrowy clearline, który będzie usuwał wszystkie znaki, aż do napotkania znaku przejścia do nowej linii (ten znak także należy usunąć ze strumienia) lub znaku końca pliku
istream& streams::clearline(istream& is) {
    string n;
    getline(is, n);
    return is;
}

// zdefiniuj również manipulator z parametrem ignore (int x), którego zadaniem będzie pominięcie x znaków ze strumienia wejściowego
istream& streams::operator>>(istream& is, const streams::ignore& ign) {
    char z;
    int acc = 0;
    while (acc < ign.x) {
        acc++;
        z = is.get();
        // chyba że wcześniej zostanie wyjęty znak przejścia do nowej linii lub stumień się skończy
        if (z == EOF or z == '\n') { 
            break;
        }
    }
    return is;
}

streams::ignore::ignore(int x)
{
    if (x < 0) {
        throw invalid_argument("ignore(): numer nie moze byc ujemny");
    }
    this->x = x;
}

//..................................................................................

// zdefiniuj bezparametrowe manipulatory comma wypisujący przecinek z odstępem ", "
ostream& streams::comma(ostream& os) {
    os << ", ";
    return os;
}

// zdefiniuj bezparametrowe manipulatory colon wypisujący dwukropek z odstępem ": "
ostream& streams::colon(ostream& os) {
    os << ": ";
    return os;
}

// Zdefiniuj także manipulator z parametrem index (int x, int w), który wypisze liczbę x w nawiasach kwadratowych i na liczbę tą przeznaczy co najmniej w pozycji (dosuń liczbę do prawego nawiasu kwadratowego)
ostream& streams::operator<<(ostream& os, const streams::index& idx) {
    os << "[";
    auto number = to_string(idx.x);
    int offset = idx.w - number.length();
    for (int i = 0; i < offset; i++) {
        os << " ";
    }
    os << number;
    os << "]";
    return os;
}

streams::index::index(int x, int w)
{
    if (w < 0) {
        throw invalid_argument("index(): nie moze byc ujemny");
    }
    this->x = x;
    this->w = w;
}
