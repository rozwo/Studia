//nie cos tu nie gra

/*
Róża Wójcicka
lista 4: zadanie 2
C# mcs
*/
using System;
using System.Collections;
using System.Collections.Generic;


public class MyEnumerator : IEnumerator<string>
{
    private int n;

    private int mIndex = 0;

    public int Current => MyEnumerator(mIndex);

    object IEnumerator.Current => Current;

    public MyEnumerator(int n)
    {
        string s1 = "b";
        string s2 = "a";
        if(n == 1)
        {
            return s1;
        }
        if(n == 2)
        {
            return s2;
        }
        for(int i = 3; i <= n; i++)
        {
            string tmp = s2;
            s2 = s2 + s1;
            s1 = tmp;
        }
        return s2;
    }

    public void Dispose()
    {

    }

    public bool MoveNext()
    {
        mIndex++;
        return mIndex <= n;
    }

    public void Reset()
    {
        mIndex = 0;
    }
}

class SlowaFibonaciego : IEnumerable<string>
{
    private int n;
    public SlowaFibonaciego(int n)
    {
        this.n = n;
    }
    public IEnumerator GetEnumerator()
    {
        return new MyEnumerator(n);
    }
    IEnumerator<string> IEnumerable<string>.GetEnumerator()
    {
        return new MyEnumerator(n);
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
