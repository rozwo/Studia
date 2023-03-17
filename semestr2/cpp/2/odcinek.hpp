#include "punkt.hpp"

class odcinek {
    private:
        punkt i;
        punkt j;
    public:
        odcinek(punkt a, punkt b); 
        odcinek(const odcinek &t);
        odcinek& operator=(const odcinek& a);
        punkt wez_punkt_i();
        punkt wez_punkt_j();
        void translacja(const wektor& a);
        void obrot(double alpha, const punkt& b);
        void sym_punkt(const punkt& b);
        void sym_os_x();
        void sym_os_y();
        double dlugosc();
        bool nalezy(punkt a);
};
