using System;
using System.IO;

class ObslugaPliku {
    public static string CzytajZPliku(string sciezka) {
        string dane = "";
        try {
            dane = File.ReadAllText(sciezka);
        }
        catch (FileNotFoundException) {
            Console.WriteLine("plik nie istnieje");
        }
        return dane;
    }
    public static void WpiszDoPliku(string sciezka, string dane) {
        try {
            File.WriteAllText(sciezka,dane);
        }
        catch(Exception wyjatek) {
            Console.WriteLine($"wystapil blad podczas zapisu do pliku ({wyjatek.Message})");
        }
    }
    public static void EdytujPlik(string sciezka, string dane, int miejsce) {
        try {
            string zawartosc = File.ReadAllText(sciezka);
            zawartosc[miejsce] = dane;
            File.WriteAllText(sciezka, zawartosc);
        }
        catch (Exception wyjatek) {
            Console.WriteLine($"wystapil blad podczas dodawania danych do pliku ({wyjatek.Message})");
        }
    }
    public static void UsunPlik(string sciezka) {
        try {
            File.Delete(sciezka);
        }
        catch (FileNotFoundException) {
            Console.WriteLine("plik nie istnieje");
        }
        catch (Exception wyjatek) {
            Console.WriteLine($"wystapil blad podczas usuwania pliku ({wyjatek.Message})");
        }
    }
}

class MenadzerPliku {
    private string sciezka;
    public MenadzerPliku(string sciezka) {
        this.sciezka = sciezka;
    }
    public void CzytajDane() {
        string dane = ObslugaPliku.CzytajZPliku(sciezka);
        Console.WriteLine("zawartosc pliku:");
        Console.WriteLine(dane);
    }
    public void WpiszDane(string dane) {
        ObslugaPliku.WpiszDoPliku(sciezka,dane);
        Console.WriteLine("dane zostaly zapisane do pliku");
    }
    public void EdytujDane(string dane, int miejsce) {
        ObslugaPliku.EdytujPlik(sciezka,dane,miejsce);
        Console.WriteLine("dane zostaly zmienione");
    }
    public void UsunDane(string miejsce) {
        ObslugaPliku.EdytujPlik(sciezka,"",miejsce);
        Console.WriteLine("dane zostaly usuniete z pliku");
    }
    public void UsunPlik() {
        ObslugaPliku.UsunPlik(sciezka);
        Console.WriteLine("plik zostal usuniety");
    }
}

class Program {
    static void Main(string[] args) {
        string sciezka = "dane.txt";
        MenadzerPliku menadzerPliku = new MenadzerPliku(sciezka);

        if (!File.Exists(sciezka)) {
            ObslugaPliku.WpiszDoPliku(sciezka,"");
            Console.WriteLine("nowy plik zostal utworzony");
        }

        while (true) {
            Console.WriteLine("\nWybierz akcję:");
            Console.WriteLine("1. Odczytaj dane z pliku");
            Console.WriteLine("2. Wpisz dane do pliku");
            Console.WriteLine("3. Edytuj dane w pliku");
            Console.WriteLine("4. Usun dane z pliku");
            Console.WriteLine("5. Usun plik");
            Console.WriteLine("6. Wyjdz");

            Console.Write("Wybor: ");
            string choice = Console.ReadLine();

            switch (choice) {
                case "1":
                    menadzerPliku.CzytajDane();
                    break;
                case "2":
                    Console.Write("wprowadz dane do zapisania: ");
                    string dane = Console.ReadLine();
                    menadzerPliku.WpiszDane(dane);
                    break;
                case "3":
                    Console.Write("wprowadz dane do zmiany: ");
                    string dane = Console.ReadLine();
                    Console.Write("podaj indeks, gdzie chcesz zmienic dane: ");
                    int miejsce = int.Parse(Console.ReadLine());
                    menadzerPliku.EdytujDane(dane, miejsce);
                    break;
                case "4":
                    Console.Write("podaj indeks, gdzie chcesz usunac dane: ");
                    int miejsce = int.Parse(Console.ReadLine());
                    menadzerPliku.UsunDane(miejsce);
                    break;
                case "5":
                    menadzerPliku.UsunPlik();
                    break;
                case "6":
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("nieprawidlowy wybor");
                    break;
            }
        }
    }
}
