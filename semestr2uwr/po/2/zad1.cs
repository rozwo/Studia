/*
Róża Wójcicka
lista 2: zadanie 1
C# mcs
*/

using System;

class IntStream
{
    protected int k=-1;
    virtual public int next()
    {
        k++;
        return k;
    }
    public void reset()
    {
        k=-1;
    }
    virtual public bool eos()
    {
        if(k>int.MaxValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class PrimeStream : IntStream
{
    bool pierwsze(int n)
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
    override public int next()
    {
        k++;
        while(!pierwsze(k))
        {
            k++;
        }
        return k;
    }
    override public bool eos()
    {
        int n=k;
        if(next()<0)
        {
            k=n;
            return true;
        }
        else
        {
            k=n;
            return false;
        }
    }
}

class RandomStream : IntStream
{
    override public int next()
    {
        Random rnd = new Random();
        return rnd.Next();
    }
    override public bool eos()
    {
        return false;
    }
}

class RandomWordStream
{
    PrimeStream prims = new PrimeStream();
    public string next()
    {
        string litery = "abcdefghijklmnoprstuwyz";
        string s="";
        int n=prims.next();
        for(int i=0;i<n;i++)
        {
            RandomStream rands = new RandomStream();
            s=s+litery[rands.next()%23];
        }
        return s;
    }

}

class Program
{
    static void Main(string[] args)
    {
        IntStream ints = new IntStream();
        PrimeStream prims = new PrimeStream();
        RandomWordStream randws = new RandomWordStream();
        
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        ints.reset();
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        System.Console.WriteLine(ints.next());
        
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

        System.Console.WriteLine(randws.next());
        System.Console.WriteLine(randws.next());
        System.Console.WriteLine(randws.next());
        System.Console.WriteLine(randws.next());
        System.Console.WriteLine(randws.next());
        System.Console.WriteLine(randws.next());

    }
}