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
    for(int i=0;i<n;i++)
    {
		for(int j=1;j<n-i;j++)
		{
		    if(t[j-1]>t[j])
                {
                    swap(t[j-1], t[j]);
                }
		}
    }
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

