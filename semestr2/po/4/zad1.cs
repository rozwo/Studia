/*
Róża Wójcicka
lista 4: zadanie 1
C# mcs
*/

using System;
using System.Collections;
using System.Collections.Generic;

interface IListCollection
{
    int next();
    void reset();
    bool eos();
}

class IntStream : IListCollection, IEnumerable<int>, IEnumerator<int>
{
    int k;

    public IntStream()
    {
        this.k = -1;
    }

    public int next()
    {
        if(this.k >= -1 && this.k < int.MaxValue)
        {
            this.k += 1;
            return this.k;
        }
        else //gdy wyjde poza int.MaxValue
        {
           return -1;
        }
    }

    public void reset()
    {
        this.k = -1;
    }

    public bool eos()
    {
        if(this.k > int.MaxValue || this.k < -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public IEnumerator<int> GetEnumerator()
    {
        return this;
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return this;
    }

    public int Current { get { return this.k; } }

    public bool MoveNext()
    {
        next();
        return !(eos());
    }

    public void Reset()
    {
        reset();
    }

    public void Dispose()
    {

    }

    object IEnumerator.Current { get { return this.k; } }

    public override string ToString()
    {
        if (this.k >= 0) return this.k.ToString();
        return "";
    }

    public int this[int indeks]
    {
        get
        {
            if(indeks < 0 || indeks > int.MaxValue)
            {
                return -1;
            }
            return indeks;
        }
    }

    public int Length
    {
        get
        {
            if(this.k == -1) return -1;
            if(this.k < 0) return 0;
            return this.k + 1;
        }
    }
}

class PrimeStream : IListCollection
{
    bool pierwsze(int n)
    {
        if(n <= 1)
        {
            return false;
        }
        if(n == 2)
        {
            return true;
        }
        if(n % 2 == 0)
        {
            return false;
        }
        for(int i = 3; i * i <= n; i = i + 2)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int k;

    public PrimeStream()
    {
        this.k = 1;    
    }

    public int next()
    {
        int wartosc = 1;

        if(this.k == int.MaxValue || this.k < 0) 
        {
            return -1; //gdy wyjde poza int.MaxValue
        }

        for(int i = this.k + 1; i <= int.MaxValue; i++) 
        {
            if(pierwsze(i))
            {
                wartosc = i;
                break;
            }
        }

        this.k = wartosc;

        return wartosc;
    }

    public bool eos()
    {
        if(this.k < 0 || this.k >= int.MaxValue)
        {
            return true;
        }
        return false;
    }

    public void reset()
    {
        this.k = 1;
    }
}

class Program
{
    static void Main(string[] args)
    {
        //gdy wychodzimy poza zakres program wypisuje -1

        IntStream ints = new IntStream();
        
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        ints.reset();
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        ints.reset();

        System.Console.WriteLine(ints[20]);
        System.Console.WriteLine(ints[20].ToString());
        (ints[20].ToString()).GetType();
        int i = 0;
        foreach(int s in ints)
        {
            System.Console.WriteLine(s);
            i++;
            if(i == 15) break;
        }
        
        PrimeStream prims = new PrimeStream();
        
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        prims.reset();
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        System.Console.WriteLine(prims.next());
        prims.reset();

        
    }
}