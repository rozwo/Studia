package figury;
import java.lang.Math;

public class Punkt extends Figury
{
    private double x;
    private double y;

    public Punkt(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void przesun(Wektor v) {
        this.x += v.getX();
        this.y += v.getY();
    }
    
    public void obrot(Punkt p, double kat) {
        double pomx = this.x - p.x;
        double pomy = this.y - p.y;
                            //zmieniam st na radiany
        this.x = (pomx * Math.cos(kat * Math.PI / 180)) -
                  (pomy * Math.sin(kat * Math.PI / 180));
        this.y = (pomy * Math.cos(kat * Math.PI / 180)) +
                  (pomx * Math.sin(kat * Math.PI / 180));
        this.x += p.x;
        this.y += p.y;
    }
    
    public void odbij(Prosta p) {
        //cos tu...
    }

    //z c++
    // void punkt::sym_punkt(const punkt& b)
    // {
    //     this.obrot(180,b);
    // }
    // void punkt::sym_os_x() {
    //     this.y = - this.y;
    // }
    // void punkt::sym_os_y() {
    //     this.x = - this.x;
    // }
}