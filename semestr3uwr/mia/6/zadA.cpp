#include <bits/stdc++.h>
using namespace std;

bool podz_przez_60(string y) {
    int suma=0, d=y.length(), czy0=0, parz=0;
    for(int i=0; i<d; i++) {
        int x=y[i]-'0';
        suma = suma + x;
        if(x==0) czy0++;
        if(x%2==0) parz++;
        // cout<<endl<<x;
    }
    if(suma%3 == 0) {
        // cout<<endl<<parz<<" "<<czy0<<endl;
        if(parz>=2 && czy0>=1) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    // magiczne linijki
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    string wyniki[n];
    for(int p=0;p<n;p++) {
        string y;
        cin>>y;
        if(podz_przez_60(y)) {
            // cout<<"red"<<endl;
            wyniki[p]="red";
        }
        else {
        // cout<<"cyan"<<endl;
        wyniki[p]="cyan";
        }
    }
    for(int w=0; w<n; w++) { 
        cout<<wyniki[w]<<endl;
    }
}