#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[201][201];

int suma(int x, int y) {
    int s=a[x][y];
    int i=x-1;
    int j=y-1;
    while(i>=0 and j>=0) {
        s=s+a[i][j];
        i=i-1;
        j=j-1;
    }
    i=x+1;
    j=y-1;
    while(i<n and j>=0) {
        s=s+a[i][j];
        i=i+1;
        j=j-1;
    }
    i=x-1;
    j=y+1;
    while(i>=0 and j<m) {
        s=s+a[i][j];
        i=i-1;
        j=j+1;
    }
    i=x+1;
    j=y+1;
    while(i<n and j<m) {
        s=s+a[i][j];
        i=i+1;
        j=j+1;
    }
    return s;
}

int main() {
    int p;
    cin>>p;
    int wyniki[p];
    for(int i=0; i<p; i++) {
        wyniki[i]=0;
    }
    for(int proba=0;proba<p;proba++) {
        cin>>n>>m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>a[i][j];
            }
        }
        int maks=0;
        for(int x=0; x<n; x++) {
            for(int y=0; y<m; y++) {
                int s=suma(x,y);
                if(s>maks) {
                    maks=s;
                }
            }
        }
        wyniki[proba]=maks;
    }

    for(int w=0; w<p; w++) { 
        cout<<wyniki[w]<<endl;
    }
}