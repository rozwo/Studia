def sito(n):
    n=n+1
    s=[0,0]
    for i in range(n-2):
        s.append(1)
    j=2
    while j<n:
        i=j+1
        while i<n:
            if i%j==0:
                s[i]=0
            i=i+1
        j=j+1
    for i in range(n):
        if s[i]==1:
            print(i,end=" ")
    print()

n=int(input('Podaj n: '))
sito(n)

"""
    for i in range(n):
        if i!=2 and i%2==0:
            s[i]=0
    j=3
    while j<n:
        i=j+1
        while i<n:
            if i%j==0:
                s[i]=0
            i=i+1
        j=j+2
"""
