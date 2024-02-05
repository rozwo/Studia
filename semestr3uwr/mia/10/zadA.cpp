#include <bits/stdc++.h>
using namespace std;

string mirror(string s, long long k) {
    string x="";
    for(long long i=0; i<=k; i++) {
        x+=s[i];
    }
    for(long long i=k; i>=0; i--) {
        x+=s[i];
    }
    return x;
}

int main() {
    long long t;
    cin>>t;
    string wyniki[t];
    for(long long p=0;p<t;p++) {
        long long n, k=0;
        string s;
        cin>>n>>s;
        if(s[0]!=s[1]) {
            while(k+1<s.length() and s[k]>=s[k+1]) {
                if(s[k]>s[k+1]) {
                    k++;
                } else {
                    if(mirror(s,k)>mirror(s,k+1)) {
                        k++;
                    } else {
                        break;
                    }
                }
            }
        }
        wyniki[p]=mirror(s,k);
    }
    for(long long w=0; w<t; w++) { 
        cout<<wyniki[w]<<endl;
    }
}
