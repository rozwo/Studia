def liczby_pierwsze(n):
    L=[]
    for i in range(n-2):
        L.append(i+2)
    for i in range(n-2):
        if L[i]!=2 and L[i]%2==0:
            L[i]=0
    for j in range(n-2):
        for i in range(n-2):
            if L[j]!=0 and L[i]!=L[j] and L[i]%L[j]==0:
                L[i]=0
    L=sorted(L)
    ile=0
    for i in range(n-2):
        if(L[i]!=0):
            break
        ile=ile+1
    L=L[ile:]
    return L

def lustrzane(x):
    y=0
    for i in range(len(str(x))):
        y=y*10+x%10
        x=x//10
    return y

def czy_palindrom(n):
    if lustrzane(n)==n:
        return True
    else:
        return False

def palindromy(a,b): #palindromiczne liczby pierwsze z przedzialu <a,b>
    L=liczby_pierwsze(b+1)
    for i in range(len(L)):
        if czy_palindrom(L[i])==False:
            L[i]=0
    L=sorted(L)
    ile=0
    for element in L:
        if element>=a:
            break
        ile=ile+1
    L=L[ile:]
    return L

a=int(input('Podaj a: '))
b=int(input('Podaj b: '))
print(palindromy(a,b))

