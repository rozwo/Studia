#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[200];

bool szukaj_litery(char l, int k) { //, string a[]) {
    for(int i=0; i<n; i++) {
        if(a[i][k]==l) {
            return true;
        }
    }
    return false;
}

string spodoba() { //string a[]) {
    string imie="vika", akt="";
    int k=0;
    while(k<m) {
        char l=imie[akt.length()];
        if(szukaj_litery(l,k)) { //,a)) {
            akt=akt+l;
        }
        if(imie==akt) {
            return "YES";
        }
        k++;
    }
    return "NO";
}

int main() {
    // n=3;
    // m=6;
    // string t[]={"mvikam","mvikam","mvikam"};
    // cout<<spodoba(t)<<endl;
    int p;
    cin>>p;
    string wyniki[p];
    for(int i=0; i<p; i++) {
        wyniki[i]=" ";
    }
    for(int proba=0;proba<p;proba++) {
        cin>>n>>m;
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        wyniki[proba]=spodoba(); //a);
    }
    for(int w=0; w<p; w++) { 
        cout<<wyniki[w]<<endl;
    }
}