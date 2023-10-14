def czy_palindrom(n):
    x=n
    y=0
    while x>0:
        y=y*10+x%10
        x=x/10
    if y==n:
        return y
    else:
        return y

n=int(input('liczba '))
print(czy_palindrom(n))
