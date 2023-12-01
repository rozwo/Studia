#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    // long long a[n], b[m];
    vector<long long> a(n);
    vector<long long> b(m);
    string w="";
    for(long long i=0; i<n; i++) {
        cin>>a[i];
    }
    for(long long i=0; i<m; i++) {
        cin>>b[i];
    }
    // sort(a,a+n);
    sort(a.begin(), a.end());
    for(long long i=0; i<m; i++) {
        long long ile;
        // long long j=0;
        // while(a[j]<=b[i]) {
        //     j++;
        //     ile++;
        // }
        //upper_bound -> (operacja wyszukiwania binarnego) zwraca iterator do pierwszego elementu większego od wartość
        ile = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        if(i!=m) {
            w = w + to_string(ile) + " ";
        } else {
            w = w + to_string(ile);
        }
    }
    cout<<w<<endl;
}