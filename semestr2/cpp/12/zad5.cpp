#include <bits/stdc++.h>
using namespace std;

// void printCollatz(int n) {
//     cout << n << " ";
//     if (n == 1) { // koniec
//         return;
//     }
//     if (n % 2 == 0) { //parzysta
//         printCollatz(n / 2);
//     }
//     else { //nieparzysta
//         printCollatz(3 * n + 1);
//     }
// }

int main() {
    function<void(int)> printCollatz = [&](int n) {
        cout << n << " ";
        if (n == 1) { // koniec
            return;
        }
        if (n % 2 == 0) { //parzysta
            printCollatz(n / 2);
        }
        else { //nieparzysta
            printCollatz(3 * n + 1);
        }
    };
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;
    printCollatz(n);
    cout << endl;

    return 0;
}
