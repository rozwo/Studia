import java.util.Scanner;

public class Urodziny {
    static String[] rzymskie = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    static int[] arabskie = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };

    public static String rzymska(int x) {
        if (x <= 0 || x >= 4000) {
            throw new IllegalArgumentException("Liczba " + x + " spoza zakresu 1-3999");
        }
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
        // String[] zwierzeta = {
        //     "Szczur", "Bawół", "Tygrys", "Królik", "Smok", "Wąż",
        //     "Koń", "Owca", "Małpa", "Kurczak", "Pies", "Świnia"
        // };
        // // 1912 to pierwszy rok znaku zodiaku (Szczura) (z googla)
        // return zwierzeta[(rok - 1912) % 12];

        
        switch((rok - 1912) % 12) {
            case 0 -> {return "Szczur";}
            case 1 -> {return "Bawół";}
            case 2 -> {return "Tygrys";}
            case 3 -> {return "Królik";}
            case 4 -> {return "Smok";}
            case 5 -> {return "Wąż";}
            case 6 -> {return "Koń";}
            case 7 -> {return "Owca";}
            case 8 -> {return "Małpa";}
            case 9 -> {return "Kurczak";}
            case 10 -> {return "Pies";}
            case 11 -> {return "Świnia";}
            default -> {return "nieznany";}
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // Ogólnie mówiąc, tworzymy tu obiekt klasy Scanner,
        // dzięki niemu wywołamy metodę pobierającą tekst z klawiatury.

        System.out.print("Podaj swoje imię: ");
        String imie = scan.nextLine();
        System.out.print("Podaj rok urodzenia: ");
        int rokuro = scan.nextInt();
        scan.close();

        String rokrzym = rzymska(rokuro);
        String zwierze = patronchinski(rokuro);

        System.out.println("Cześć " + imie + "!");
        System.out.println("Twój rok urodzenia w zapisie rzymskim: " + rokrzym);
        System.out.println("Twój patron w kalendarzu chińskim: " + zwierze);
    }
}
