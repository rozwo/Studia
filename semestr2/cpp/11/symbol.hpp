#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace kalkulator {
    class symbol {
        public:
            static double ostatecznyWynik();

            symbol() {};
            virtual ~symbol() {};
            virtual void wykonaj() = 0; // metoda wirtualna

        protected:
            static stack<symbol*> stos; // statyczny stos, na którym oparte jest działanie kalkulatora
    };
}

