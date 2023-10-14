#include<bits/stdc++.h>

using namespace std;


void losuj(int n, int t[])
{
    for(int i=0; i<n; i++)
    {
        t[i]=rand()%201;
    }
}

void wypisz(int n, int t[])
{
    for(int i=0; i<n; i++)
    {
        cout.width(4);
        cout<<t[i]<<" ";
    }
}

void uporzadkuj(int n, int t[])
{
    int pmin = 0, pmax = n - 1, p;
    do
    {
        p = -1;
        for(int i = pmin; i < pmax; i++)
        {
            if(t[i] > t[i+1])
            {
                swap(t[i], t[i+1]);
                if(p < 0) pmin = i;
                p = i;
            }
        }
        if(pmin) pmin--;
        pmax = p;
    } while(p >= 0);
}
int t[10000000];
int main()
{
    int n;
    cin>>n;


    cout<<endl;

    srand(time(NULL));

    losuj(n,t);
    wypisz(n,t);
    cout<<endl;
    uporzadkuj(n,t);
    wypisz (n,t);
    cout<<endl;


    return 0;
}

