# Róża Wójcicka
# lista 9: zadanie 1
# jezyk Ruby
# w Ruby Mine
#
class Funkcja
    #gdzie definicja funkcji jest zadana blokiem (a właściwie obiektem klasy Proc) w konstruktorze
    def initialize(proc)
        throw :invalid_function unless proc.is_a?(Proc) #ta czesc wzielam z internetu...
        @proc = proc
    end
    #.value(x) oblicza wartość funkcji w punkcie x
    def value(x)
        return @proc.call(x)
    end
    #.zero(a,b,e) oblicza miejsca zerowe funkcji w przedziale [a, b] z dokładnością e lub zwraca nil jeśli miejsce zerowe nie zostanie znalezione
    def zero(a,b,e)
        middle = (a+b)/2    #srodek przedzialu
        fa = value(a)   #wartosc funkcji na krancach
        fb = value(b)   #wartosc funkcji na krancach
        fmid = value(middle)    #wartosc funkcji w srodku przedzialu
        if fa.abs < e   #sprawdzam krance przedzialu
            return fa
        elsif fb.abs < e    #drugi kraniec
            return fb
        elsif fmid.abs < e  #jesli trafilam to wypisuje
            return middle
        elsif fa*fmid < 0   #jak nie trafilam to zawezam przedzial
            return zerowe(a, middle, e)
        elsif fmid*fb < 0   #zawezam przedzial cd
            return zerowe(middle, b, e)
        else    #wpp
            return nil
        end
    end
    #.field(a,b) oblicza przybliżone pole powierzchni między wykresem a osią OX w przedziale [a, b]. Można przyjąć, że wykres jest zawsze powyżej osi OX
    def field(a,b)  #rekurencyjnie licze pole pod wykresem
        @@d = 0.001   #z jakas dokladnoscia
        if a >= b #przedzial jest pusty wiec pole wynosi zero
            return 0
        else  #wpp dodajemy pole trapezu do reszty pola
            y1 = value(a).to_f
            y2 = value(a + @@d).to_f
            return ((y1 + y2) * 0.5 * @@d) + field(a + @@d, b)
        end
    end
    #.deriv(x) oblicza wartość (przybliżoną) pochodnej w punkcie x
    def deriv(x)
        @@delta = 0.000001
        return (value(x + @@delta) - value(x)) / @@delta
    end
end

