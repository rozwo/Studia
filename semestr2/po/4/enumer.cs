using System;
using System.Collections;
using System.Collections.Generic;


public class MyInfiniteEnumerator : IEnumerator<int>
{
    private int[] mValues;

    private int mIndex = -1;

    //public int Current { get; private set; } = 0;
    public int Current => mValues[mIndex];

    object IEnumerator.Current => Current;

    public MyInfiniteEnumerator(int[] values)
    {
        mValues = values;
    }

    public void Dispose()
    {

    }

    public bool MoveNext()
    {
        //Current++;
        //return true;
        mIndex++;
        return mIndex < mValues.Length;
    }

    public void Reset()
    {
        //Current = 0;
        mIndex = 0;
    }
}

public class MyInfiniteEnumerable : IEnumerable<int>
{
    private int[] mMyData = new[] { 4, 5, 6 };

    public IEnumerator GetEnumerator()
    {
        return new MyInfiniteEnumerator(mMyData);
    }
    IEnumerator<int> IEnumerable<int>.GetEnumerator()
    {
        return new MyInfiniteEnumerator(mMyData);
    }
}

class Program
{
    static void Main(string[] args)
    {
        System.Console.WriteLine("Hello World!");
        
        /*
        var array = new int[] { 1, 2, 3 };
        for (var i = 0; i < array.length; i++)
        {
            System.Console.WriteLine($"A is {array[i]}");
        }
        
        array.GetEnumerator();

        foreach (var a in array)
        {
            System.Console.WriteLine($"A is {a}");
        }
        
        var enumerator = array.GetEnumerator();

        while (enumerator.MoveNext())
        {
            System.Console.WriteLine($"Enumerator A is {enumerator.Current}");
        }
        */
        var infenu = new MyInfiniteEnumerable();
        /*
        foreach (var i in infenu)
        {
            System.Console.WriteLine($"I is {i}");
        }
        */
        var enumerator = infenu.GetEnumerator();

        while (enumerator.MoveNext())
        {
            System.Console.WriteLine($"Enumerator A is {enumerator.Current}");
        }

        Console.ReadLine();
    }
}
