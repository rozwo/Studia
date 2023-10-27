/*
  Copyright (c) October 2012 by Paweł Rzechonek
  Drzewo obliczeń.
  Istotne elementy w programie:
    * import statyczny;
    * jawne wywołanie konstruktora klasy bazowej w konstruktorze;
    * implementacja odziedziczonej metody abstrakcyjnej.
*/

package obliczenia;

import static java.lang.Math.*;

public class WartBezwzgl extends Operator1Arg
{
    public WartBezwzgl (Wyrazenie a1) {
        super(a1);
    }

    public int oblicz () {
        return abs(arg1.oblicz());
    }
    public String toString () {
        return "|"+arg1+"|";
    }
}

