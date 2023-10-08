def suma(x,y,a,n,m):
    s=a[x][y]
    i=x-1
    j=y-1
    while i>=0 and j>=0:
        s=s+a[i][j]
        i=i-1
        j=j-1
    i=x+1
    j=y-1
    while i<n and j>=0:
        s=s+a[i][j]
        i=i+1
        j=j-1
    i=x-1
    j=y+1
    while i>=0 and j<m:
        s=s+a[i][j]
        i=i-1
        j=j+1
    i=x+1
    j=y+1
    while i<n and j<m:
        s=s+a[i][j]
        i=i+1
        j=j+1
    return s

p=int(input(''))
wyniki=[0]*p
for proba in range(p):
    ipt=input('')
    n=int(ipt[0])
    m=int(ipt[2])
    a = [[0] * m for i in range(n)]
    for i in range(n):
        linia=input('')
        l=0
        for j in range(m):
            a[i][j]=int(linia[l])
            l=l+2
    maks=0
    for x in range(n):
        for y in range(m):
            s=suma(x,y,a,n,m)
            if s>maks:
                maks=s
    wyniki[proba]=maks

for w in wyniki:    
    print(w)