#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int t[n+1];
    for(int i=1; i<=n; i++) {
        cin>>t[i];
    }
    string w="NO";
    for(int i=1; i<=n; i++) {
        if(t[t[t[i]]]==i && t[i]!=i) {
            w="YES";
            break;
        }
    }
    cout<<w<<endl;
}