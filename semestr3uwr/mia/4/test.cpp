
#include <bits/stdc++.h>
using namespace std;
 
long long ciecie(long long n, long long wlosy[], long long l) {
    long long pom[n], ile=0;
    for(int i = 0; i < n; i++) {
        pom[i] = 0;
    }
    for(long long i=0; i<n; i++) {
        if(i==0) {
            if(wlosy[0]>l) {
                pom[0]=1;
            }
            else {
                pom[0]=0;
            }
        }
        else if(wlosy[i]>l) {
            if(pom[i-1]==0) {
                pom[i]=1;
                ile++;
            }
            else {
                pom[i]=2;
            }
        }
        else {
            pom[i]=0;
        }
    }
    return ile;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m, l, i=0;
    cin>>n>>m>>l;
    long long wlosy[n], wyniki[m];
    for(long long b=0; b<n; b++) {
        cin>>wlosy[b];
    }
    for(long long k=0; k<m; k++) {
        long long a, p;
        cin>>a;
        if(a == 1) {
            long long d;
            cin>>p>>d;
            p--;
            wlosy[p] += d;
        }
        else {
            if(i==0) {
                wyniki[i]=ciecie(n, wlosy, l);
            }
            else {
                if(wlosy[p]>l) {
                    if(p==0) {
                        if(wlosy[p+1]>l) {
                            wyniki[i]=wyniki[i-1];
                        }
                        else {
                            wyniki[i]=wyniki[i-1]+1;
                        }
                    }
                    else if(p==n-1) {
                        if(wlosy[p-1]>l) {
                            wyniki[i]=wyniki[i-1];
                        }
                        else {
                            wyniki[i]=wyniki[i-1]+1;
                        }
                    }
                    else {
                        if(wlosy[p-1]>l && wlosy[p+1]>l) {
                            wyniki[i]=wyniki[i-1]-1;
                        }
                        else if(wlosy[p-1]<=l && wlosy[p+1]<=l) {
                            wyniki[i]=wyniki[i-1]+1;
                        }
                        else {
                            wyniki[i]=wyniki[i-1];
                        }
                    }
                }
                else {
                    wyniki[i]=wyniki[i-1];
                }
            }
            i++;
        }
    }
    for(long long w=0; w<i; w++) { 
        cout<<wyniki[w]<<endl;
    }
}