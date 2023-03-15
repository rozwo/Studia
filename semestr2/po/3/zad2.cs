/*
    Róża Wójcicka
    lista 3: zadanie 2
    jezyk C# 
    kompilacja  mcs -t:library zad2.cs
                mcs -r:zad2.dll main2.cs
    uruchomienie ./main2.exe
*/

using System;
namespace MyDKV
{
    public class MyDictionary<K,V> where K : IEquatable<K> 
    {
        class Elem 
        {
            public K key;
            public V val;
            public Elem next;
            public Elem prev;
            public Elem(K key, V val)
            {
                this.prev = null;
                this.next = null;
                this.key = key;
                this.val = val;
            }
        }
        Elem pocz;
        Elem kon;
        public void add(K elemk,V elemv) 
        {
            if(pocz == null)
            {
                pocz = new Elem(elemk,elemv);
                kon = pocz;
            }
            else
            {
                Elem ed = new Elem(elemk,elemv);
                kon.next = ed;
                ed.prev = kon;
                kon = ed;
            }
        }
        public void delete(K elemk)
        {
            if(pocz == null)
            {
                throw new System.Exception("error");
            }
            else
            {
                Elem pom = pocz;
                while (!elemk.Equals(pom.key) && pom != kon.next)
                {
                    pom = pom.next;
                }
                if(pom == kon.next)
                {
                    throw new System.Exception("error");
                }
                else
                {
                    if(pom == pocz)
                    {
                        pocz = pocz.next;
                    }
                    else if(pom == kon)
                    {
                        kon = kon.prev;
                    }
                    else
                    {
                        pom.prev.next = pom.next;
                        pom.next.prev = pom.prev;
                    }
                }
            }
        }
        public V search(K elemk)
        {
            if(pocz == null)
            {
                throw new System.Exception("error");
            }
            else
            {
                Elem pom = pocz;
                while (!elemk.Equals(pom.key) && pom != kon.next)
                {
                    pom = pom.next;
                }
                if(pom == kon.next)
                {
                    throw new System.Exception("error");
                }
                else
                {
                    return pom.val;
                }
            }
        }
        public void print_list()
        {
            Elem pom = pocz;
            while (pom != kon.next)
            {
                System.Console.Write(pom.key);
                System.Console.Write(',');
                System.Console.Write(pom.val);
                System.Console.Write(' ');
                pom = pom.next;
            }
            System.Console.WriteLine();
        }
    }
}

