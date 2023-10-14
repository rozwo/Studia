#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,x,y,ile=0;
    cin>>n>>x>>y;
    string ciag;
    cin>>ciag;
    for(long long i=1; i<n; i++) {
        if(ciag[i-1]=='0' and ciag[i]=='1') {
            ile++;
        }
    }
    if(ciag[n-1]=='0') {
        ile++;
    }
    //ile bloczkow 0 na wejsciu
    //ile*cneg (czyli ile*y)
    //lub
    //(ile-1)*crev+1*cneg (czyli (ile-1)*x+y)
    long long c1=ile*y, c2=(ile-1)*x+y;
    if(ile==0) {
        cout<<0;
    }
    else if(c1>c2) {
        cout<<c2;
    }
    else {
        cout<<c1;
    }
}