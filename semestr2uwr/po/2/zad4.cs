/*
Róża Wójcicka
lista 2: zadanie 4
C# mcs
*/

using System;
using System.Collections.Generic;
using System.Linq;

class LazyIntList
{
    protected List<int> lista = new List<int>();
    virtual public int element(int i)
    {
        if(this.lista.Count<i)
        {
            int j=this.lista.Count;
            while(j<i)
            {
                j++;
                this.lista.Add(j);
            }
        }
        return this.lista.ElementAt(i - 1); //i - 1 bo w zadaniu numeracja od 1 a w liście od 0
    }
    public int size()
    {
        return this.lista.Count;
    }
}

class LazyPrimeList : LazyIntList
{
    protected List<int> lista = new List<int>();
    bool Prime(int n)
    {
        if(n<=1)
        {
            return false;
        }
        if(n==2)
        {
            return true;
        }
        if(n%2==0)
        {
            return false;
        }
        for(int i=3;i*i<=n;i=i+2)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    override public int element(int i)
    {
        if(this.lista.Count<i)
        {
            int j=this.lista.Count;
            while(j<i)
            {
                int k=1;
                if(j>0)
                {
                    k=this.lista.ElementAt(j - 1) + 1;  //j - 1 za numerowanie od 0 w liście
                }
                while(!Prime(k))
                {
                    k++;
                }
                this.lista.Add(k);
                
                j++;    //j++ na koniec pętli bo problemy wczesniej
            }
        }
        return this.lista.ElementAt(i - 1); //i - 1 bo w zadaniu numeracja od 1 a w liście od 0
    }
}

class Program
{
    static void Main(string[] args)
    {
        LazyIntList lazl = new LazyIntList();
        System.Console.WriteLine(lazl.element(31));
        System.Console.WriteLine(lazl.size());
        System.Console.WriteLine(lazl.element(11));
        System.Console.WriteLine(lazl.size());
        LazyPrimeList lazpl = new LazyPrimeList();
        System.Console.WriteLine(lazpl.element(5));
        System.Console.WriteLine(lazpl.element(10));
        System.Console.WriteLine(lazpl.element(8));
    }
}
