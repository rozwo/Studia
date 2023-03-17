#include "globalne.hpp"
using namespace std;

int main()
{
    /////punkt
    punkt a0 = punkt();
    cout << "Punkt " << a0.wsp_x() << " " << a0.wsp_y() << endl;

    punkt a1 = punkt (1, 1);
    cout << "Punkt " << a1.wsp_x() << " " << a1.wsp_y() << endl;

    a0 = a1;
    cout << "Punkt " << a0.wsp_x() << " " << a0.wsp_y() << endl;

    a1.~punkt();
    cout << "Punkt " << a1.wsp_x() << " " << a1.wsp_y() << endl;

    cout << "Odleglosc " << odleglosc(a0, a1) << endl;

    a0.obrot(90, a1);
    cout << "Obrot o 90st " << a0.wsp_x() << " " << a0.wsp_y() << endl;

    wektor b0 = wektor(1, 1);
    punkt a3 = punkt(1, 1);
    a3.translacja(b0);
    cout << "Przesuniety o wektor " << a3.wsp_x() << " " << a3.wsp_y() << endl;

    a1 = punkt(3, 1);
    a1.sym_punkt(punkt(0, 0));
    cout << "Sym wzg punktu " << a1.wsp_x() << " " << a1.wsp_y() << endl;

    a1.sym_os_x();
    cout << "Sym wzg osi ox " << a1.wsp_x() << " " << a1.wsp_y() << endl;

    a1.sym_os_y();
    cout << "Sym wzg osi oy " << a1.wsp_x() << " " << a1.wsp_y() << endl;

    cout << endl;

    /////odcinek
    odcinek k = odcinek(punkt(1, 0), punkt(1, 1));
    cout << "pocz odc " << k.wez_punkt_i().wsp_x() << " " << k.wez_punkt_i().wsp_y()
        << ", kon odc " << k.wez_punkt_j().wsp_x() << " " << k.wez_punkt_j().wsp_y() << endl;

    k.translacja(wektor(1, 1));
    cout << "Przesuniety o wektor ";
    cout << "pocz odc " << k.wez_punkt_i().wsp_x() << " " << k.wez_punkt_i().wsp_y()
        << ", kon odc " << k.wez_punkt_j().wsp_x() << " " << k.wez_punkt_j().wsp_y() << endl;

    a0 = punkt(0, 0);
    k.obrot(90, a0);
    cout << "obrocony o 90st wzg (0,0) ";
    cout << "pocz odc " << k.wez_punkt_i().wsp_x() << " " << k.wez_punkt_i().wsp_y()
        << ", kon odc " << k.wez_punkt_j().wsp_x() << " " << k.wez_punkt_j().wsp_y() << endl;

    k.sym_punkt(a0);
    cout << "sym wzg punktu (0,0) ";
    cout << "pocz odc " << k.wez_punkt_i().wsp_x() << " " << k.wez_punkt_i().wsp_y()
        << ", kon odc " << k.wez_punkt_j().wsp_x() << " " << k.wez_punkt_j().wsp_y() << endl;

    k.sym_os_x();
    cout << "sym wzg osi ox ";
    cout << "pocz odc " << k.wez_punkt_i().wsp_x() << " " << k.wez_punkt_i().wsp_y()
        << ", kon odc " << k.wez_punkt_j().wsp_x() << " " << k.wez_punkt_j().wsp_y() << endl;

    k.sym_os_y();
    cout << "sym wzg osi oy ";
    cout << "pocz odc " << k.wez_punkt_i().wsp_x() << " " << k.wez_punkt_i().wsp_y()
        << ", kon odc " << k.wez_punkt_j().wsp_x() << " " << k.wez_punkt_j().wsp_y() << endl;

    k = odcinek(punkt(1, 0), punkt(1, 1));
    odcinek l = odcinek(punkt(0, 0), punkt(0, 1));
    odcinek m = odcinek(punkt(0, 0), punkt(1, 0));
    odcinek n = odcinek(punkt(0, 0), punkt(1, 1));

    cout << "Dlugosc odcinka " << k.dlugosc() << endl;

    cout << "Czy (1,0.5) nalezy do odcinka k? " << k.nalezy(punkt(1, 0.5)) << endl;
    cout << "Czy (12,0.5) nalezy do odcinka k? " << k.nalezy(punkt(12, 0.5)) << endl;

    cout << "Czy k i l sa rownolegle? " << rownolegle(k, l) << endl;   // tak
    cout << "Czy k i m sa rownolegle? " << rownolegle(k, m) << endl;   // nie
    cout << "Czy l i m sa prostopadle? " << prostopadle(l, m) << endl; // tak
    cout << "Czy l i n sa prostopadle? " << prostopadle(l, n) << endl; // nie
    cout << endl;
    /////trojkat
    trojkat t = trojkat(punkt(0, 0), punkt(1, 0), punkt(0, 1));
    cout << "wierzcholek d " << t.wez_punkt_d().wsp_x() << " " << t.wez_punkt_d().wsp_y();
    cout << " wierzcholek e " << t.wez_punkt_e().wsp_x() << " " << t.wez_punkt_e().wsp_y();
    cout << " wierzcholek f " << t.wez_punkt_f().wsp_x() << " " << t.wez_punkt_f().wsp_y() << endl;

    t.translacja(wektor(1, 1));
    cout << "Przesuniety o wektor";
    cout << "wierzcholek d " << t.wez_punkt_d().wsp_x() << " " << t.wez_punkt_d().wsp_y();
    cout << " wierzcholek e " << t.wez_punkt_e().wsp_x() << " " << t.wez_punkt_e().wsp_y();
    cout << " wierzcholek f " << t.wez_punkt_f().wsp_x() << " " << t.wez_punkt_f().wsp_y() << endl;

    t.obrot(90, a0);
    cout << "obrocony o 90st wzg (0,0) ";
    cout << "wierzcholek d " << t.wez_punkt_d().wsp_x() << " " << t.wez_punkt_d().wsp_y();
    cout << " wierzcholek e " << t.wez_punkt_e().wsp_x() << " " << t.wez_punkt_e().wsp_y();
    cout << " wierzcholek f " << t.wez_punkt_f().wsp_x() << " " << t.wez_punkt_f().wsp_y() << endl;

    t.sym_punkt(a0);
    cout << "sym wzg punktu (0,0) ";
    cout << "wierzcholek d " << t.wez_punkt_d().wsp_x() << " " << t.wez_punkt_d().wsp_y();
    cout << " wierzcholek e " << t.wez_punkt_e().wsp_x() << " " << t.wez_punkt_e().wsp_y();
    cout << " wierzcholek f " << t.wez_punkt_f().wsp_x() << " " << t.wez_punkt_f().wsp_y() << endl;

    t.sym_os_x();
    cout << "sym wzg osi ox ";
    cout << "wierzcholek d " << t.wez_punkt_d().wsp_x() << " " << t.wez_punkt_d().wsp_y();
    cout << " wierzcholek e " << t.wez_punkt_e().wsp_x() << " " << t.wez_punkt_e().wsp_y();
    cout << " wierzcholek f " << t.wez_punkt_f().wsp_x() << " " << t.wez_punkt_f().wsp_y() << endl;

    t.sym_os_y();
    cout << "sym wzg osi oy ";
    cout << "wierzcholek d " << t.wez_punkt_d().wsp_x() << " " << t.wez_punkt_d().wsp_y();
    cout << " wierzcholek e " << t.wez_punkt_e().wsp_x() << " " << t.wez_punkt_e().wsp_y();
    cout << " wierzcholek f " << t.wez_punkt_f().wsp_x() << " " << t.wez_punkt_f().wsp_y() << endl;

    t = trojkat(punkt(0, 0), punkt(1, 0), punkt(0, 1));
    cout << "Obwod trojkata t " << t.obwod() << endl;
    cout << "Pole trojkata t " << t.pole() << endl;

    cout << "Czy punkt (0.2,0.5) nalezy do trojkata t? " << t.nalezy(punkt(0.2, 0.5)) << endl; // nalezy
    cout << "Czy punkt (2,0.5) nalezy do trojkata t? " << t.nalezy(punkt(2, 0.5)) << endl;     // nie nalezy

    cout << "Czy trojkaty sa rozlaczne? " << rozlaczne(trojkat(punkt(-3, 0), punkt(3, 0), punkt(0, 3)), trojkat(punkt(-2, 0), punkt(2, 0), punkt(0, 2))) << endl; // nie

    cout << "Czy trojkat pierwszy zawiera drugi? " << zawiera(trojkat(punkt(-3, 0), punkt(3, 0), punkt(0, 3)), trojkat(punkt(-2, 0), punkt(2, 0), punkt(0, 2))) << endl; // tak

    return 0;
}
