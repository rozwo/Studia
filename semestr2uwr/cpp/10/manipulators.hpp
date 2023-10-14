#include <bits/stdc++.h>
using namespace std;

namespace streams {
    
    istream& clearline(istream& is);

    class ignore
    {
        int x;
        friend istream& operator>>(istream& is, const ignore& ign);
    public:
        ignore(int x);
    };

    istream& operator>>(istream& is, const ignore& ign);

    ostream& comma(ostream& os);

    ostream& colon(ostream& os);

    class index
    {
        int x;
        int w;
        friend ostream& operator<<(ostream& os, const index& idx);
    public:
        index(int x, int w);
    };

    ostream& operator<<(ostream& os, const index& idx);
}

