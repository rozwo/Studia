# zadanie 1 wariant C

class Wyrazenie:
    def oblicz(self, zmienne):
        raise NotImplementedError("cos nie dziala (oblicz)")
    def pochodna(self, zmienne):
        raise NotImplementedError("cos nie dziala (pochodna)")
    def __str__(self):
        raise NotImplementedError("cos nie dziala (str)")
    def __add__(self, other):
        return Dodaj(self, other)
    def __mul__(self, other):
        return Razy(self, other)
    
class VariableNotFoundException(Exception):
    pass

class Zmienna(Wyrazenie):
    def __init__(self, nazwa):
        self.nazwa = nazwa
    def oblicz(self, zmienne):
        if self.nazwa in zmienne:
            return zmienne[self.nazwa]
        else:
            raise VariableNotFoundException(f"zmienna '{self.nazwa}' nie ma przypisanej wartosci")
    def pochodna(self, zmienne):
        return 1
    def __str__(self):
        return self.nazwa

class Stala(Wyrazenie):
    def __init__(self, wartosc):
        self.wartosc = wartosc
    def oblicz(self, zmienne):
        return self.wartosc
    def pochodna(self, zmienne):
        return 0
    def __str__(self):
        return str(self.wartosc)

class Dodaj(Wyrazenie):
    def __init__(self, w1, w2):
        self.w1 = w1
        self.w2 = w2
    def oblicz(self, zmienne):
        return self.w1.oblicz(zmienne) + self.w2.oblicz(zmienne)
    def pochodna(self, zmienne):
        return self.w1.pochodna(zmienne) + self.w2.pochodna(zmienne)
    def __str__(self):
        return f"({str(self.w1)} + {str(self.w2)})"

class Razy(Wyrazenie):
    def __init__(self, w1, w2):
        self.w1 = w1
        self.w2 = w2
    def oblicz(self, zmienne):
        return self.w1.oblicz(zmienne) * self.w2.oblicz(zmienne)
    def pochodna(self, zmienne):
        # if self.w1 == self.w2:
        #     return 
        # else:
        return  (self.w1.pochodna(zmienne) * self.w2.oblicz(zmienne)) + (self.w1.oblicz(zmienne) * self.w2.pochodna(zmienne))
    def __str__(self):
        return f"({str(self.w1)} * {str(self.w2)})"


wyrazenie = Razy(Dodaj(Zmienna("x"), Stala(2)), Zmienna("y"))
zmienne = {"x": 3, "y": 4}
print(wyrazenie.oblicz(zmienne))
print(wyrazenie.pochodna(zmienne))
print(str(wyrazenie))

