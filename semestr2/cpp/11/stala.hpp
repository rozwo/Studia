#pragma once
#include "operand.hpp"
#include <string>
#include <map>
using namespace std;

namespace kalkulator {
    class stala : public operand {
        public:
            const string nazwa;
            const double wartosc;

            static double pobierzStala(string nazwa);
            stala(string, double);
            virtual ~stala() {};
            double pobierzWartosc();

        private:
            static map<string, double> mapaStalych;
    };
}

