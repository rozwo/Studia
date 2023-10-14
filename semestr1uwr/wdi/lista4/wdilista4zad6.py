def palindrom(x):
    for i in range(len(x)-1):
        if x[i] != x[len(x)-1-i]:
            return False
    return True

def k_arna(d,k):
    s=""
    while d>0:
        s=str(d%k)+s
        d=d//k
    return s

n=int(input('Podaj n: '))
k=int(input('Podaj k: '))
print(k_arna(n,k))
print(palindrom(k_arna(n,k)))
