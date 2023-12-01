#include <iostream>
#include <math.h>
// #include <string>

int main() {
    int k;
    int x = 0;
    std::string s, t;
    std::cin >> k;
    for(int i = 0; i < k; i++) {
        x = 0;
        std::cin >> s >> t;
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == 'a') {
                x = 1;
                break;
            }
        }
        if(t == "a") {
            std::cout << "1" << std::endl;
        } else if(x == 1) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << (long long)pow(2, s.size()) << std::endl;
        }
    }

}