def dzielniki_pierwsze(n):
    L=[]
    if n%2==0:
        L.append(2)
        while n%2==0:
            n=n/2
    i=3
    while i<=n:
        if n%i==0:
            L.append(i)
            while n%i==0:
                n=n/i
        i=i+2
    return L

n=int(input('Podaj liczbe: '))
print(dzielniki_pierwsze(n))
