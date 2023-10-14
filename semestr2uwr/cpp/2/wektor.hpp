#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const double pi = M_PI;

class wektor {
    private:
        double a, b;
    public:
        wektor();
        wektor(double x, double y);
        double wsp_a();
        double wsp_b();
};
