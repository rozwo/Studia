#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p;
    cin>>p;
    string wyniki[p];
    for(int proba=0;proba<p;proba++) {
        int a,k,r;
        cin>>a>>k>>r;
        if(r%2==1) {
            a++;
        }
        if(a>k) {
            wyniki[proba]="First";
        } else {
            wyniki[proba]="Second";
        }
    }
    for(int w=0; w<p; w++) { 
        cout<<wyniki[w]<<endl;
    }
}