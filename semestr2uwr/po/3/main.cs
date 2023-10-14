/*
    Róża Wójcicka
    lista 3: zadanie 1
    jezyk C# 
    kompilacja  mcs -t:library zad1.cs
                mcs -r:zad1.dll main.cs
    uruchomienie ./main.exe
*/
using System;
using MyList;

class Program
{
    static void Main(string[] args)
    {
        Lista<int> lista = new Lista<int>();
        //czy lista jest pusta
        System.Console.WriteLine(lista.is_empty());
        //dodaje x z przodu
        lista.push_front(6);
        lista.print_list();
        //dodaje x z tylu
        lista.push_back(8);
        lista.print_list();
        //dodaje x z przodu
        lista.push_front(4);
        lista.print_list();
        //dodaje x z przodu
        lista.push_front(2);
        lista.print_list();
        //dodaje x z tylu
        lista.push_back(10);
        lista.print_list();
        //dodaje x z tylu
        lista.push_back(12);
        lista.print_list();
        //usuwam ostatni element
        System.Console.WriteLine(lista.pop_back());
        lista.print_list();
        //usuwam pierwszy element
        System.Console.WriteLine(lista.pop_front());
        lista.print_list();
        //usuwam ostatni element
        System.Console.WriteLine(lista.pop_back());
        lista.print_list();
        //usuwam pierwszy element
        System.Console.WriteLine(lista.pop_front());
        lista.print_list();
        //czy lista jest pusta
        System.Console.WriteLine(lista.is_empty());
    }
}