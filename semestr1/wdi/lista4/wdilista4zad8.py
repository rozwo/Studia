def sortowanie(L):
    for i in range(len(L)):
        j=len(L)-1
        while j>i:
            if L[j]<L[j-1]:
                tmp=L[j]
                L[j]=L[j-1]
                L[j-1]=tmp
            j-=1
    return L

def podobne(n,m):
    nn=list(str(n))
    mm=list(str(m))
    nn=sortowanie(nn)
    mm=sortowanie(mm)
    if nn==mm:
        return True
    else:
        return False

n=int(input('Podaj n: '))
m=int(input('Podaj m: '))
print(podobne(n,m))
