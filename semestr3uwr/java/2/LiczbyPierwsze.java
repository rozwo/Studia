public final class LiczbyPierwsze {
    private final static int POTEGA2 = 21;
    private final static int[] SITO = new int[1 << POTEGA2];
    // potrzebny jest statyczny blok inicjalizacyjny dla sita
    // [0, 1, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, ... ]
    // moja wersja [0, 1, 0, 0, 2, 0, 2, 0, 2, 3, 2, 0, ... ]
    static {
        for (int i = 2; i < SITO.length; i++) {
            if (SITO[i] == 0) {
                for (int j = i; j < SITO.length; j += i) {
                    if (SITO[j] == 0) {
                        SITO[j] = i;
                    }
                }
            }
        }
    }
    public static boolean czyPierwsza (long x) {
        if (x <= 1) {
            return false;
        }
        if (x < SITO.length) {
            return SITO[(int) x] == 0; //w sicie 0 oznacza, że liczba jest pierwsza
        }
        for (long i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static long[] naCzynnikiPierwsze (long x) {
        if(x == 0 || x == 1 || x == -1) {
            return new long[]{x};
        }
        long[] czynniki = new long[64]; //bo 2^6
        int index = 0;
        if (x < 0) {
            czynniki[index++] = -1;
            x = -x;
            if(x < 0) {
                czynniki[index++] = 2;
                x /= -2;
            }
        }
        while (x > 1) {
            if(x < SITO.length) {
                int dzielnik = SITO[(int) x];
                if (dzielnik == 0) {
                    czynniki[index++] = x;
                    break;
                } else {
                    czynniki[index++] = dzielnik;
                    x /= dzielnik;
                }
            }
            else {
                long i = 2;
                while(x % i != 0 && i <= (long)Math.sqrt(x)) {
                    i += 1;
                }
                if (x % i == 0) {
                    czynniki[index++] = i;
                    x /= i;
                }
                else {
                    czynniki[index++] = x;
                    x = 1;
                }
            }
        }
        long[] wynik = new long[index];
        for (int i = 0; i < index; i++) {
            wynik[i] = czynniki[i];
        }
        return wynik;
    }
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("program wywołano bez żadnego parametru");
            return;
        }
        for (String arg : args) {
            long liczba = Long.parseLong(arg); //parseLong zmienia ze stringa w long
            long[] czynnikiPierwsze = naCzynnikiPierwsze(liczba);
            System.out.print(liczba + " = ");
            for (int i = 0; i < czynnikiPierwsze.length; i++) {
                System.out.print(czynnikiPierwsze[i]);
                if (i < czynnikiPierwsze.length - 1) {
                    System.out.print(" * ");
                }
            }
            System.out.println();
        }
    }
}
