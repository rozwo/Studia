/*
  Copyright (c) October 2012 by Paweł Rzechonek
  Drzewo obliczeń.
  Istotne elementy w programie:
    * klasa abstarkcyjna dziedzicząca po innej klasie abstarkcyjnej;
    * pole finalne inicjalizowane w konstruktorze.
*/

package obliczenia;

public abstract class Operator1Arg extends Wyrazenie
{
    protected final Wyrazenie arg1;

    public Operator1Arg (Wyrazenie a1) {
        if (a1==null) throw new IllegalArgumentException();
        arg1 = a1;
    }
}

