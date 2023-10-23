#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n=50;
    double x=2.0;
    //orginalna
    for(int k=2; k<n; k++) {
        x = pow(2,k-1)*sqrt(2*(1-sqrt((1-pow(x/pow(2,k-1),2)))));
        cout<<x<<endl;
    }
    cout<<endl;
    x=2.0;
    //uproszczona
    for(int k=2; k<n; k++) {
        x = x*sqrt(2/(1+sqrt(1-pow(x/pow(2,k-1),2))));
        cout<<x<<endl;
    }
}

