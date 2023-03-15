/*
    Róża Wójcicka
    lista 3: zadanie 1
    jezyk C# 
    kompilacja  mcs -t:library zad1.cs
                mcs -r:zad1.dll main.cs
    uruchomienie ./main.exe
*/

using System;
namespace MyList
{
    public class Lista<T>
    {
        class Elem //bo potrzebuje T do tej klasy a nie ma zmiennych globalnych
        {
            public T val;
            public Elem next;
            public Elem prev;
            public Elem(T val)
            {
                this.prev = null;
                this.next = null;
                this.val = val;
            }
        }
        Elem pocz;
        Elem kon;
        public void push_front(T elem) //tworze nowy element (ed - element dodawany) ktorego wartosc to elem, ma byc na poczatku wiec ed.next to pocz i zmieniam pocz na ed
        {
            if(pocz == null)
            {
                pocz = new Elem(elem);
                kon = pocz;
            }
            else //(jak na wdi) zmienna pomocnicza ide od poczatku do konca czyli momentu gdy pom bedzie == null i wypisuje po drodze
        
            {
                Elem ed = new Elem(elem);
                ed.next = pocz;
                pocz.prev = ed;
                pocz = ed;
            }
        }
        public void push_back(T elem) //tworze nowy element (ed - element dodawany) ktorego wartosc to elem, ma byc na koncu wiec kon.next to ed i zmieniam kon na ed
        {
            if(pocz == null)
            {
                pocz = new Elem(elem);
                kon = pocz;
            }
            else
            {
                Elem ed = new Elem(elem);
                kon.next = ed;
                ed.prev = kon;
                kon = ed;
            }
        }
        public T pop_front() //zapamietuje wartosc poczatku, zmieniam poczatek na nastepny i wypisuje wartosc poprzedniego pocz
        {
            if(pocz == null)
            {
                throw new System.Exception("error");
            }
            else
            {
                T v = pocz.val;
                pocz = pocz.next;
                return v;
            }
        }
        public T pop_back() //zapamietuje wartosc konca, zmieniam koniec na poprzedni i wypisuje wartosc poprzedniego kon
        {
            if(pocz == null)
            {
                throw new System.Exception("error");
            }
            else
            {
                T v = kon.val;
                kon = kon.prev;
                return v;
            }
        }
        public bool is_empty()
        {
            return pocz == null;
        }
        public void print_list() //(jak na wdi) zmienna pomocnicza ide od poczatku do konca czyli momentu gdy pom bedzie == null i wypisuje po drodze
        {
            Elem pom = pocz;
            while (pom != kon.next)
            {
                System.Console.Write(pom.val);
                System.Console.Write(' ');
                pom = pom.next;
            }
            System.Console.WriteLine();
        }
    }
}

