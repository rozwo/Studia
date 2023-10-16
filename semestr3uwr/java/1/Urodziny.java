import java.util.Scanner;

public class Urodziny {

    public static String rzymska(int x) {
        if (x <= 0 || x >= 4000) {
            throw new IllegalArgumentException("Liczba " + x + " spoza zakresu 1-3999");
        }
        String[] rzymskie = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };
        int[] arabskie = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        String liczrzym = "";
        int i = 0;
        while (x > 0) {
            if (x >= arabskie[i]) {
                liczrzym += rzymskie[i];
                x -= arabskie[i];
            }
            else {
                i++;
            }
        }
        return liczrzym.toString();
    }

    public static String patronchinski(int rok) {
        String[] zwierzeta = {
            "Szczur", "Bawół", "Tygrys", "Królik", "Smok", "Wąż",
            "Koń", "Owca", "Małpa", "Kurczak", "Pies", "Świnia"
        };
        // 1924 to pierwszy rok znaku zodiaku (Szczura) (z googla)
        return zwierzeta[(rok - 1912) % 12];
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // Ogólnie mówiąc, tworzymy tu obiekt klasy Scanner,
        // dzięki niemu wywołamy metodę pobierającą tekst z klawiatury.

        System.out.print("Podaj swoje imię: ");
        String imie = scan.nextLine();
        System.out.print("Podaj rok urodzenia: ");
        int rokuro = scan.nextInt();

        String rokrzym = rzymska(rokuro);
        String zwierze = patronchinski(rokuro);

        System.out.println("Cześć " + imie + "!");
        System.out.println("Twój rok urodzenia w zapisie rzymskim: " + rokrzym);
        System.out.println("Twój patron w kalendarzu chińskim: " + zwierze);
    }
}
