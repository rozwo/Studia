package figury;

public class Odcinek extends Figury
{
    private Punkt punkt1;
    private Punkt punkt2;

    public Odcinek(Punkt punkt1, Punkt punkt2) {
        if (punkt1.getX() == punkt2.getX() && punkt1.getY() == punkt2.getY()) {
            throw new IllegalArgumentException("odcinka o dlugosci 0 nie istnieje");
        }
        this.punkt1 = punkt1;
        this.punkt2 = punkt2;
    }

    public void przesun(Wektor v) {
        this.punkt1.przesun(v);
        this.punkt2.przesun(v);
    }

    public void obrot(Punkt p, double kat) {
        this.punkt1.obrot(p,kat);
        this.punkt2.obrot(p,kat);
    }

    public void odbij(Prosta p) {
        this.punkt1.odbij(p);
        this.punkt2.odbij(p);
    }
}

