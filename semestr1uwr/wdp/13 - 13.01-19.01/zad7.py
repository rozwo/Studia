class Ulamek:
    def __init__(self,p,q):
        self.p=p
        self.q=q

    def __str__(self):
        return f'{self.p}/{self.q}'

    def __add__(self,other):
        return f'{self.p*other.q+other.p*self.q}/{self.q*other.q}'

    def __mul__(self,other):
        return f'{self.p*other.p}/{self.q*other.q}'

    def __sub__(self,other):
        return f'{self.p*other.q-other.p*self.q}/{self.q*other.q}'

    def __truediv__(self,other):
        return f'{self.p*other.q}/{self.q*other.p}'

    def __eq__(self,other):
        return (self.p*other.q)==(other.p*self.q)

    def __lt__(self,other):
            if (self.p*other.q)<(other.p*self.q):
                return True
            else:
                return False


u1=Ulamek(1,2)
u2=Ulamek(1,3)
u3=Ulamek(25,26)

print(u1+u2)
print(u3-u2)
print(u1*u3)
print(u3/u1)
print(u1<u2)
print(u1<u3)


