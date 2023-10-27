/*
  Copyright (c) October 2012 by Paweł Rzechonek
  Drzewo obliczeń.
  Istotne elementy w programie:
    * pole finalne inicjalizowane w konstruktorze;
    * implementacja odziedziczonej metody abstrakcyjnej.
*/

package obliczenia;

public class Liczba extends Wyrazenie
{
    protected final int liczba;

    public Liczba (int l) {
        liczba = l;
    }

    public int oblicz () {
        return liczba;
    }
    public String toString () {
        return String.valueOf(liczba);
    }
}

