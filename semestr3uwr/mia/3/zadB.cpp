#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int d=min(min(a,b),c), f=max(max(a,b),c), e=a+b+c-d-f, maks=0;
    for(int i=0; i<=n/f; i++) {
        for(int j=0; j<=n/e; j++) {
            int x=n-i*f-j*e;
            if(x%d==0) {
                if(i+j+(x/d) > maks) {
                    maks = i+j+(x/d);
                }
            }
        }
    }
    cout<<maks<<endl;
}
