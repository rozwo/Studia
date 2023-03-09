#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, string>> rzym = {
{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

string ara_na_rzym(int n)
{
    string r="";
    for(auto e: rzym)
    {
        while(n-e.first>=0)
        {
            r=r+e.second;
            n=n-e.first;
        }
    }
    return r;
}


int main(int argc, char *argv[])
{
    for(int i=1; i<argc; i++)
    {
        int n=0;
        try
        {
            n=stoi(argv[i]);
        }
        catch(...)
        {
            std::clog <<"blad - podany argument nie jest liczba"<< '\n';
            continue;
        }
        if(to_string(n)!=argv[i])
        {
            clog <<"blad - podany argument nie jest liczba"<< '\n';
            continue;
        }
        if(n>0 and n<4000)
        {
            clog<<ara_na_rzym(n) <<endl;
        }
        else
        {
            clog <<"blad - podana liczba nie jest z przedzialu od 1 do 3999"<<endl;
        }
    }
    return 0;
}