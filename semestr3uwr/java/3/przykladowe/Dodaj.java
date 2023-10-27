/*
  Copyright (c) October 2012 by Paweł Rzechonek
  Drzewo obliczeń.
  Istotne elementy w programie:
    * jawne wywołanie konstruktora klasy bazowej w konstruktorze;
    * implementacja odziedziczonej metody abstrakcyjnej.
*/

package obliczenia;

import static java.lang.Math.*;

public class Dodaj extends Operator2Arg
{
    public Dodaj (Wyrazenie a1, Wyrazenie a2) {
        super(a1,a2);
    }

    public int oblicz () {
        return arg1.oblicz()+arg2.oblicz();
    }
    public String toString () {
        return "("+arg1+" + "+arg2+")";
    }
}

