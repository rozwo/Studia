#include <iostream>
#include <math.h>
using namespace std;

double f(double x) {
    return 4046/(pow(pow(x,14)+1,1/2)+1);
}

int main() {
    cout<<f(0.001)<<endl;
}

