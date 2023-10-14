/*
Róża Wójcicka
lista 4: zadanie 2
C# mcs
*/

using System;
using System.Collections;
using System.Collections.Generic;
//yield <- fajne cos jak return ale nie konczy programu dopoki nie trafi na yield break

class SlowaFibonaciego : IEnumerable<string>
{
    private int n;
    public SlowaFibonaciego(int n)
    {
        this.n = n;
    }
    public IEnumerator<string> GetEnumerator()
    {
        string s1 = "b";
        string s2 = "a";
        if(n < 1)
        {
            yield break;
        }
        yield return s1;
        if(n == 1)
        {
            yield break;
        }
        yield return s2;
        if(n == 2)
        {
            yield break;
        }
        for(int i = 3; i <= n; i++)
        {
            string tmp = s2;
            s2 = s2 + s1;
            s1 = tmp;
            yield return s2;
        }
        yield break;
    }
    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

class Program
{
    static void Main(string[] args)
    {
        SlowaFibonaciego sf = new SlowaFibonaciego(13);
        foreach(string s in sf)
        {
            System.Console.WriteLine(s);
        }
    }
}
