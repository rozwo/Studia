#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    string miejsca;
    cin>>miejsca;
    int ile=0;
    for(int i=0;i<n;i++) {
        if(miejsca[i]=='.') {
            if(i==0) {
                if(a<b) {
                    if(b>0) {
                        miejsca[0]='b';
                        b--;
                        ile++;
                    }
                }
                else if(a>0) {
                    miejsca[0]='a';
                    a--;
                    ile++;
                }
            }
            else {
                if(miejsca[i-1]=='a') {
                    if(b>0) {
                        miejsca[i]='b';
                        b--;
                        ile++;
                    }
                }
                else if(miejsca[i-1]=='b') {
                    if(a>0) {
                        miejsca[i]='a';
                        a--;
                        ile++;
                    }
                }
                else {
                    if(a<b) {
                        if(b>0) {
                            miejsca[i]='b';
                            b--;
                            ile++;
                        }
                    }
                    else if(a>0) {
                        miejsca[i]='a';
                        a--;
                        ile++;
                    }
                }
            }
        }
    }
    cout<<ile;
}