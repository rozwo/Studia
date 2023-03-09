def szachownica(n,k):
    for i in range(n):
        for j in range(k):
            for l in range(n):
                print(k*' ',k*'#',sep="",end="")
            print()
        for j in range(k):
            for l in range(n):
                print(k*'#',k*' ',sep="",end="")
            print()

n=int(input("Podaj n: "))
k=int(input("Podaj k: "))
szachownica(n,k)
