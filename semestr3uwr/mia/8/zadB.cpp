#include <bits/stdc++.h>
using namespace std;

long long Newton(int n, int k) {
    if(k==0 || k==n) return 1;
    double w=1;
    for(int i=1; i<=k; i++) {
        w=w*(n-i+1)/i;
    }
    return (long long)w;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int k;
    cin>>k;
    long long kol[k], w=0, wynik=1;
    for(int i=0; i<k; i++) {
        cin>>kol[i];
    }
    for(int i=0; i<k; i++) {
        w+=kol[i];
    }
    for(int i=k-1; i>=0; i--) {
        wynik*=Newton(w-1,kol[i]-1);
        w-=kol[i];
    }
    wynik%=1000000007;
    cout<<wynik<<endl;
}