def koperta(n):
    print((2*n+1)*'*',sep="")
    for i in range(n-1):
        print('*',i*' ','*',(2*n-2*i-3)*' ','*',i*' ','*',sep="")
    print('*',(n-1)*' ','*',(n-1)*' ','*',sep="")
    for i in range(n-1):
        print('*',(n-i-2)*' ','*',(2*i+1)*' ','*',(n-i-2)*' ','*',sep="")
    print((2*n+1)*'*',sep="")


n=int(input("Podaj n: "))
koperta(n)
