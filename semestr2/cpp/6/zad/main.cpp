#include"Operator2arg.hpp"

int main() {

    Zmienna::dod_zmienna("x", 5);
    Zmienna::dod_zmienna("y", 9);

    //wyrazenia podane w zadaniu
    Wyrazenie* w1 = new Dziel(
        new Mnoz(
            new Odej(
                new Zmienna("x"),
                new Liczba(1)
            ),
            new Zmienna("x")
        ),
        new Liczba(2)
    );

    Wyrazenie* w2 = new Dziel(
        new Dod(
            new Liczba(3),
            new Liczba(5)
        ),
        new Dod(
            new Liczba(2),
            new Mnoz(
                new Zmienna("x"),
                new Liczba(7)
            )
        )
    );

    Wyrazenie* w3 = new Odej(
        new Dod(
            new Liczba(2),
            new Mnoz(
                new Zmienna("x"),
                new Liczba(7)
            )
        ),
        new Dod(
            new Mnoz(
                new Zmienna("y"),
                new Liczba(3)
            ),
            new Liczba(5)
        )
    );

    Wyrazenie* w4 = new Dziel(
        new Cos(
            new Mnoz(
                new Dod(
                    new Zmienna("x"),
                    new Liczba(1)
                ),
                new pi()
            )
        ),
        new Pot(
            new e(),
            new Pot(
                new Zmienna("x"),
                new Liczba(2)
            )
        )
    );

    Wyrazenie* w5 = new Odej(
        new pi(),
        new Dod(
            new Liczba(2),
            new Mnoz(
                new Zmienna("x"),
                new Liczba(7)
            )
        )
    );

    //testy dla podanych wartosci na poczatku
    // cout << w1->zapis() << " = " << w1->oblicz() << endl;
    // cout << w2->zapis() << " = " << w2->oblicz() << endl;
    // cout << w3->zapis() << " = " << w3->oblicz() << endl;
    // cout << w4->zapis() << " = " << w4->oblicz() << endl;

    //testy dla y=0 xe<0,1> co 0.01, dla y=0.5 xe<0,1> co 0.01, dla y=1 xe<0,1> co 0.01
    // for (double j = 0.0; j < 1.01; j += 0.5)
    // {
    //     for (double i = 0.0; i < 1.01; i += 0.01)
    //     {
    //         cout << "\n x = " << i << " ";
    //         Zmienna::zmien_wart("x", i);
    //         cout << "\n y = " << j << "\n";
    //         Zmienna::zmien_wart("y", j);
    //         cout << w1->zapis() << " = " << w1->oblicz() << endl;
    //         cout << w2->zapis() << " = " << w2->oblicz() << endl;
    //         cout << w3->zapis() << " = " << w3->oblicz() << endl;
    //         cout << w4->zapis() << " = " << w4->oblicz() << endl;
    //     }
    // }
    // cout << endl;

    double i, j;
    i = 0;
    j = 0;
    cout << "\n x = " << i << " ";
    Zmienna::zmien_wart("x", i);
    cout << "\n y = " << j << "\n";
    Zmienna::zmien_wart("y", j);
    cout << w1->zapis() << " = " << w1->oblicz() << endl;
    cout << w2->zapis() << " = " << w2->oblicz() << endl;
    cout << w3->zapis() << " = " << w3->oblicz() << endl;
    cout << w4->zapis() << " = " << w4->oblicz() << endl;
    cout << w5->zapis() << " = " << w5->oblicz() << endl;
    i = 0;
    j = 0.5;
    cout << "\n x = " << i << " ";
    Zmienna::zmien_wart("x", i);
    cout << "\n y = " << j << "\n";
    Zmienna::zmien_wart("y", j);
    cout << w1->zapis() << " = " << w1->oblicz() << endl;
    cout << w2->zapis() << " = " << w2->oblicz() << endl;
    cout << w3->zapis() << " = " << w3->oblicz() << endl;
    cout << w4->zapis() << " = " << w4->oblicz() << endl;
    cout << w5->zapis() << " = " << w5->oblicz() << endl;
    i = 0.5;
    j = 0;
    cout << "\n x = " << i << " ";
    Zmienna::zmien_wart("x", i);
    cout << "\n y = " << j << "\n";
    Zmienna::zmien_wart("y", j);
    cout << w1->zapis() << " = " << w1->oblicz() << endl;
    cout << w2->zapis() << " = " << w2->oblicz() << endl;
    cout << w3->zapis() << " = " << w3->oblicz() << endl;
    cout << w4->zapis() << " = " << w4->oblicz() << endl;
    cout << w5->zapis() << " = " << w5->oblicz() << endl;
    i = 0.5;
    j = 0.5;
    cout << "\n x = " << i << " ";
    Zmienna::zmien_wart("x", i);
    cout << "\n y = " << j << "\n";
    Zmienna::zmien_wart("y", j);
    cout << w1->zapis() << " = " << w1->oblicz() << endl;
    cout << w2->zapis() << " = " << w2->oblicz() << endl;
    cout << w3->zapis() << " = " << w3->oblicz() << endl;
    cout << w4->zapis() << " = " << w4->oblicz() << endl;
    cout << w5->zapis() << " = " << w5->oblicz() << endl;
    i = 1;
    j = 1;
    cout << "\n x = " << i << " ";
    Zmienna::zmien_wart("x", i);
    cout << "\n y = " << j << "\n";
    Zmienna::zmien_wart("y", j);
    cout << w1->zapis() << " = " << w1->oblicz() << endl;
    cout << w2->zapis() << " = " << w2->oblicz() << endl;
    cout << w3->zapis() << " = " << w3->oblicz() << endl;
    cout << w4->zapis() << " = " << w4->oblicz() << endl;
    cout << w5->zapis() << " = " << w5->oblicz() << endl;
       
    //testy sprawdzajace nie uzywane w poprzednich wyrazeniach dzialania
    Wyrazenie* w6 = new Bezwzgl(
        new Dod(
            new Przeciwna(
                new Liczba(68)
            ),
            new Sin(
                new fi()
            )
        )
    );

    // cout << w6->zapis() << " = " << w5->oblicz() << endl;

    Wyrazenie* w7 = new Ln(
        new Exp(
            new Liczba(33)
        )
    );

    // cout << w7->zapis() << " = " << w6->oblicz() << endl;

    Wyrazenie* w8 = new Mod(
        new Odwrotna(
            new Dziel(
                new Liczba(10),
                new Liczba(-2)
            )
        ),
        new Liczba(3)
    );

    // cout << w8->zapis() << " = " << w7->oblicz() << endl;

    return 0;
}