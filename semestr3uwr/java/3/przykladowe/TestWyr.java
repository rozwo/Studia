/*
  Copyright (c) October 2012 by Paweł Rzechonek
  Program testowy dla drzewa obliczeń.
*/

import obliczenia.*;

public class TestWyr
{
    public static void main (String[] args)
    {
        Wyrazenie w = new WartBezwzgl(
            new Dodaj(
                new Liczba(7),
                new Mnoz(
                    new Liczba(-3),
                    new Liczba(5)
                )
            )
        );
        System.out.println(w+" = "+w.oblicz());
    }
}

