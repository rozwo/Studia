def palindrom(x):
    for i in range(len(x)-1):
        if x[i] != x[len(x)-1-i]:
            return False
    return True

def binarna(d):
    b=""
    while d>0:
        b=str(d%2)+b
        d=d//2
    return b

n=int(input('Podaj n: '))
print(binarna(n))
print(palindrom(binarna(n)))
