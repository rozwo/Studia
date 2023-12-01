#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long wyniki[n];
    for(long long p=0;p<n;p++) {
        string s, t;
        cin>>s>>t;
        bool czya=false;
        long long i=0;
        if(t=="a") {
            wyniki[p]=1;
        }
        else {
            while(i<t.length() && czya==false) {
                if(t[i]=='a') {
                    czya=true;
                }
                i++;
            }
            if(czya) {
                wyniki[p]=-1;
            } else {
                wyniki[p]=pow(2,s.length());
            }
        }
    }
    for(long long w=0; w<n; w++) { 
        cout<<wyniki[w]<<endl;
    }
}