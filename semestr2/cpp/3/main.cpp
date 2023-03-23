#include "liczba.hpp"
using namespace std;

int main()
{
    liczba a = liczba();
    a.printl();

    a.nowa(1);
    a.printl();

    a.nowa(2);
    a.printl();

    liczba b = liczba(1);
    b.printl();

    b.nowa(2);
    b.printl();
    b.nowa(3);
    b.printl();
    b.nowa(4);
    b.printl();
    b.nowa(5);
    b.printl();
    b.nowa(6);
    b.printl();

    b.cofnij();
    b.printl();

    b.nowa(7);
    b.printl();
    b.nowa(8);
    b.printl();
    b.nowa(9);
    b.printl();

    liczba c = b;
    c.printl();

    b.nowa(10);
    b.printl();

    c.nowa(11);
    c.printl();

    a.printl();
    a = move(b);
    a.printl();

    return 0;
}
