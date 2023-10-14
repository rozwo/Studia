def F(n):
    if n%2==0:
        return n/2
    else:
        return n*3+1

def energia(a):
    e=0
    while a!=1:
        e=e+1
        a=F(a)
    return e

def suma(L):
    wynik = 0
    for element in L:
        wynik += element
    return wynik

def srednia(L):
    return suma(L)/len(L)

def mediana(L2):
    L=sorted(L2)
    if len(L)%2==0:
        return (L[len(L)//2-1]+L[len(L)//2])/2
    else:
        return L[len(L)//2]

def analiza_collatza(a,b):
    L=[]
    for i in range(b+1):
        if a<=i:
            L.append(i)
    for i in range(len(L)):
        L[i]=energia(L[i])
    print('Srednia:',srednia(L))
    print('Mediana:',mediana(L))
    print('Maksimum:',max(L))
    print('Minimum:',min(L))

a=int(input('Podaj a: '))
b=int(input('Podaj b: '))
analiza_collatza(a,b)

