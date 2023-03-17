#include "odcinek.hpp"

class trojkat
{
    private:
        punkt d;
        punkt e;
        punkt f;
    public:
        trojkat(const punkt& a, const punkt& b, const punkt& c);
        trojkat(const trojkat &t);
        trojkat& operator=(const trojkat& a);
        punkt wez_punkt_d();
        punkt wez_punkt_e();
        punkt wez_punkt_f();
        void translacja(const wektor& a);
        void obrot(double alpha, const punkt& b);
        void sym_punkt(const punkt& b);
        void sym_os_x();
        void sym_os_y();
        double obwod();
        double pole();
        bool nalezy(const punkt& c);
};
