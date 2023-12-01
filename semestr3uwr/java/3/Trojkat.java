package figury;

public class Trojkat extends Figury
{
    private Punkt punkt1;
    private Punkt punkt2;
    private Punkt punkt3;

    public Trojkat(Punkt punkt1, Punkt punkt2, Punkt punkt3) {
        if (punkt1.getX() == punkt2.getX() && punkt1.getY() == punkt2.getY() ||
            punkt1.getX() == punkt3.getX() && punkt1.getY() == punkt3.getY() ||
            punkt2.getX() == punkt3.getX() && punkt2.getY() == punkt3.getY()) {
            throw new IllegalArgumentException("punkty sa wspolliniowe - nie mozna utworzyc trojkata");
        }
        this.punkt1 = punkt1;
        this.punkt2 = punkt2;
        this.punkt3 = punkt3;
    }

    // Metody przesuń, obróć i odbij dla trójkata
    public void przesun(Wektor v) {
        this.punkt1.przesun(v);
        this.punkt2.przesun(v);
        this.punkt3.przesun(v);
    }

    public void obrot(Punkt p, double kat) {
        this.punkt1.obrot(p,kat);
        this.punkt2.obrot(p,kat);
        this.punkt3.obrot(p,kat);
    }

    public void odbij(Prosta p) {
        this.punkt1.odbij(p);
        this.punkt2.odbij(p);
        this.punkt3.odbij(p);
    }
}