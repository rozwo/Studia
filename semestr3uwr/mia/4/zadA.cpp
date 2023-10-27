#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin>>p;
    string wyniki[p];
    for(int proba=0;proba<p;proba++) {
        int n;
        cin>>n;
        int a[n];
        string w="";
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i=0; i<n; i++) {
            int ile=1;
            int j=a[i];
            while(j!=i+1) {
                j=a[j-1];
                ile++;
            }
            if(i!=n) {
                w = w + to_string(ile) + " ";
            } else {
                w = w + to_string(ile);
            }
        }
        wyniki[proba]=w;
    }
    for(int w=0; w<p; w++) { 
        cout<<wyniki[w]<<endl;
    }
}