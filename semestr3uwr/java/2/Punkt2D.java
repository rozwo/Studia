/*
  Copyright (c) October 2010 by Paweł Rzechonek
  W programie definiujemy klasę Punkt. Obiekty tej klasy będa reprezentować
  punkt na płaszczyźnie rzeczywistej z kartezjańskim układem współrzędnych.
  Istotne elementy w programie:
    * przeciążone metody i konstruktory;
    * składowe statyczne;
    * statycze i instancyjne bloki inicjalizacyjne.
*/

import static java.lang.Math.*;

// klasa reprezentująca punkt na rzeczywistej płaszczyźnie 2D
class Punkt
{
    // pola prywatne
    private double x, y;
    // instancyjny blok inicjalizacyjny
    {
        x = 1;
        y = 1;
    }

    // konstruktory publiczne
    public Punkt (double x, double y)
    {
        this.x = x; // referencja this jest tutaj konieczna
        this.y = y; // ponieważ nastąpiło przesłonięcie nazw pól w klasie przez nazy parametrów
    }
    // konstruktor domyślny (bezparametrowy)
    public Punkt ()
    {
        this(0,0); // wywołanie innego konstruktora
    }
    // konstruktor korzystający z wcześniejszej inicjalizacji
    public Punkt (double c)
    {
        x *= c;
        y *= c;
    }

    // metoda publiczna przesuwająca punkt o podany wektor
    public void przesuń (double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    // publiczne finalne pole statyczne z punktem w początku układu współrzędnych
    public final static Punkt ZERO;
    // statyczny blok inicjalizacyjny
    static
    {
        ZERO = new Punkt();
    }
    // statyczna metoda obliczająca odległość między dwoma punktami
    public static double odległość (Punkt a, Punkt b)
    {
        double dx = b.x-a.x, dy = b.y-a.y;
        return sqrt(dx*dx+dy*dy);
    }
    // metoda przeciążona obliczająca odległość punktu od początku układu współrzędnych
    public static double odległość (Punkt c)
    {
        return odległość(ZERO,c);
    }

    // metoda opisująca obiekt
    public String toString ()
    {
        return "("+x+", "+y+")";
    }
}

public class Punkt2D
{
    public static void main (String[] args)
    {
        Punkt p = new Punkt(), q = new Punkt(3,4), r = new Punkt(3);
        p.przesuń(-5,12);
        System.out.println("p = "+p);
        System.out.println("q = "+q);
        System.out.println("r = "+r);
        System.out.println("odległość od p do q = "+Punkt.odległość(p,q));
        System.out.println("odległość r od punktu (0,0) = "+Punkt.odległość(r));
    }
}

