#include <iostream>
#include <math.h>
using namespace std;

float fs(float x) {
    return 14.0*((1-cos(17*x))/(x*x));
}

double fd(double x) {
    return 14.0*((1-cos(17*x))/(x*x));
}

int main() {
    for(int i=11;i<21;i++) {
        cout<<fs(pow(10,-i))<<"   "<<fd(pow(10,-i))<<endl;
    }
}

//w jednym i drugim wypadku wychodza same 0 a powinno 2023