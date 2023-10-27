/*
  Copyright (c) October 2012 by Paweł Rzechonek
  Drzewo obliczeń.
  Istotne elementy w programie:
    * klasa abstarkcyjna dziedzicząca po innej klasie abstarkcyjnej;
    * jawne wywołanie konstruktora klasy bazowej w konstruktorze;
    * pole finalne inicjalizowane w konstruktorze.
*/

package obliczenia;

public abstract class Operator2Arg extends Operator1Arg
{
    protected final Wyrazenie arg2;

    public Operator2Arg (Wyrazenie a1, Wyrazenie a2) {
        super(a1);
        if (a2==null) throw new IllegalArgumentException();
        arg2 = a2;
    }
}

