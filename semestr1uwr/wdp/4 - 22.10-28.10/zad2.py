def pierwsza(n):
    if n==1:
        return False
    if n==2:
        return True
    for i in range(3,(n**(0,5)),2):
        if n%i==0:
            return False
    return True

def hiperszczesliwa(n,a):
    if pierwsza(n):
        n=str(n)
        s=''
        for i in range(a):
            s=s+'7'
        if s in n:
            return True
        else:
            return False
    else:
        return False
l=int(input('Podaj ilo cyfrowe: '))
a=int(input('Podaj ile 7: '))
b=10**(l-1)
c=(10**l)-1
for i in range(b,c):
    if hiperszczesliwa(i,a):
        ile=ile+1
print(ile)

