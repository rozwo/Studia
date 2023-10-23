#include <iostream>
#include <math.h>
using namespace std;

// double fd(double x) {
//     return 14.0*((1-cos(17*x))/(x*x));
// }

double f(double x) {
    return 14.0*(pow(sin(17*x),2)/((x*x)*(1+cos(17*x))));
}

int main() {
    // for(int i=11;i<21;i++) {
    //     cout<<fd(pow(10,-i))<<endl;
    // }
// // wychodza same 0 a powinno 2023

    for(int i=11;i<21;i++) {
        cout<<f(pow(10,-i))<<endl;
    }
// wychodza same 2023
}
