#include <iostream>
#include <math.h>
using namespace std;

// double y(int n) {
//     if(n == 0) {
//         return 1.00;
//     }
//     else if(n == 1) {
//         return -1.00/9.00;
//     }
//     else {
//         return (80.00/9.00)*y(n-1) + y(n-2);
//     }
// }

// int main() {
//     for(int i=2;i<51;i++) {
//         cout<<"y("<<i<<") = "<<y(i)<<endl;
//     }
// }

int main() {
    double a = 1.00;
    double b = -1.00/9.00;
    for(int i=2;i<51;i++) {
        double y = (80.00/9.00)*b + a;
        cout<<"y("<<i<<") = "<<y<<endl;
        a = b;
        b = y;
    }
}
