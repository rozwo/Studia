/*
    Róża Wójcicka
    lista 3: zadanie 2
    jezyk C# 
    kompilacja  mcs -t:library zad2.cs
                mcs -r:zad2.dll main2.cs
    uruchomienie ./main2.exe
*/
using System;
using MyDKV;

class Program
{
    static void Main(string[] args)
    {
        MyDictionary<string,int> lista = new MyDictionary<string,int>();
        //dodaje element
        lista.add("szesc",6);
        lista.print_list();
        //dodaje element
        lista.add("jeden",1);
        lista.print_list();
        //dodaje element
        lista.add("trzy",3);
        lista.print_list();
        //dodaje element
        lista.add("piec",5);
        lista.print_list();
        //dodaje element
        lista.add("dwa",2);
        lista.print_list();
        //dodaje element
        lista.add("cztery",4);
        lista.print_list();
        //wyszukaj wartosc dla klucza piec
        System.Console.WriteLine(lista.search("piec"));
        //usuwam element o kluczu szesc
        lista.delete("szesc");
        lista.print_list();
        //usuwam element o kluczu trzy
        lista.delete("trzy");
        lista.print_list();
    }
}