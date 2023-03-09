from math import sqrt
def szczesliwa(n):
    n=str(n)
    if '777' in n:
        return True
    else:
        return False

def pierwsza(n):
    if n==1:
        return False
    if n==2:
        return True
    if n%2==0:
        return False
    for i in range(3,int(sqrt(n))+1,2):
        if n%i==0:
            return False
    return True

ile=0
for i in range(1,100000):
    if szczesliwa(i):
        if pierwsza(i):
            print(i)
            ile=ile+1
print(ile)

