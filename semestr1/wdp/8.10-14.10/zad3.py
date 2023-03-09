def krzyzyk(n):
    for i in range(1,n+1):
        print(n*' ',n*'*',sep="")
    for i in range(1,n+1):
        print(n*3*'*',sep="")
    for i in range(1,n+1):
        print(n*' ',n*'*',sep="")

n=int(input('Podaj n: '))
krzyzyk(n)
