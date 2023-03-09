import random

def okazje_strzeleckie(a,b):
    FA=a[2]+random.randint(1,6)
    FD=b[1]+random.randint(1,6)
    if FA>FD:
        return FA-FD
    else:
        return 0

def gol(B,G):
    b=random.random()*B
    g=random.random()*G
    if g>b:
        return 1
    else:
        return 0

def mecz(a,b):
    L=[0,0]
    for i in range(okazje_strzeleckie(a,b)):
        L[0]=L[0]+gol(b[3],a[4])
    for i in range(okazje_strzeleckie(b,a)):
        L[1]=L[1]+gol(a[3],b[4])
    return L

def prawdopodobienstwo(a,b):
    p=0
    for i in range(100000):
        k=mecz(a,b)
        if k[0]>k[1]:
            p=p+1
    return p/100000

def rozgrywki_grupowe(g,b):
    L=[[[0],[0],[0],[0]],[[0],[0],[0],[0]],[[0],[0],[0],[0]],[[0],[0],[0],[0]]]
    for i in range(len(g)):
        j=i
        while j<len(g):
            L[i][j]=mecz(g[i],g[j])
            L[j][i]=L[i][j]
    if b==True:
        return L
    return 'nie dziala haha ha'



arabia = ('Arabia_Saudyjska', 2, 3, 0.3, 0.3)
argentyna = ('Argentyna', 4, 6, 0.5, 0.8)
meksyk = ('Meksyk', 3, 4, 0.6, 0.5) 
polska = ('Polska', 2, 3, 0.9, 0.8)

grupa = [arabia, argentyna, meksyk, polska]


print(prawdopodobienstwo(grupa[3],grupa[1]))

print(rozgrywki_grupowe(grupa,True))

