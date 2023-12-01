#include <bits/stdc++.h>
using namespace std;

bool podobne(long long n) {
    long long d=0;
    if(n%2==0) d++;
    for(long long i=3; i<n; i=i+2) {
        if(n%i==0) d++;
    }
    if(d==1) return true;
    return false;
}

int main() {
    // magiczne linijki
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;
    long long a[n];
    string wynik[n];
    for(long long i=0; i<n; i++) {
        cin>>a[i];
    }
    for(long long i=0; i<n; i++) {
        if(podobne(a[i])) wynik[i]="YES";
        else wynik[i]="NO";
    }
    for(long long w=0; w<n; w++) { 
        cout<<wynik[w]<<endl;
    }
}