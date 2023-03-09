def nwd(a,b):
    while a!=b:
       if a>b:
           a-=b
       else:
           b-=a
    return a

def nww(a,b):
    return a*b//nwd(a,b)

def ulamek(a,b):
    print(a//nwd(a,b),"/",b//nwd(a,b),sep='')

a=int(input('Podaj a: '))
b=int(input('Podaj b: '))

print(nww(a,b))
ulamek(a,b)
