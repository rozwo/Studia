#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    long long a=0, ile_przed=0, prev=0, i=0;
    while(i<s.length()) {
        int x=s[i];
        if(x%4==0) {
            a++;
        }
        if((prev*10+x)%4==0) {
            a+=ile_przed;
        }
        ile_przed++;
        prev=x;
        i++;
    }
    cout<<a<<endl;
}