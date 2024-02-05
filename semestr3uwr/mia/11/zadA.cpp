#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, current;
    cin>>n;
    int t[n+1], x=n;
    for(int i=1; i<n+1; i++) {
        t[i]=0;
    }
    for(int i=1; i<n+1; i++) {
        cin>>current;
        t[current]=1;
        if(current==x) {
            int j=current;
            while(j>0 and t[j]==1) {
                cout<<j<<" ";
                j--;
            }
            x=j;
            cout<<endl;
        } else {
            cout<<endl;
        }
    }
}