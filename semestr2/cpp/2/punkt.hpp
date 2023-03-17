#include "prosta.hpp"

class punkt {
    private:
        double x, y;
    public:
        punkt();
        punkt(double a, double b);
        ~punkt();
        punkt& operator=(const punkt& a);
        punkt(const punkt &t);
        double wsp_x();
        double wsp_y();
        void translacja(wektor a);
        void obrot(double alpha, const punkt& b);
        void sym_punkt(const punkt& b);
        void sym_os_x();
        void sym_os_y();
};

