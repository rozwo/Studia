def wieza(n):
    for k in range(n):
        i=k+1
        for j in range(3):
            print((n-i)*' ',(i+k)*'#',sep='')


def wieze(L):
    m=max(L)
    for k in range(m):
        i=k+1
        for j in range(3):
            for l in L:
                if m-i<l:
                    print((m-i)*' ',(k+i-2*(m-l))*'#',(m-i+1)*' ',sep='',end='')
                else:
                    print((l+k+l-i+1)*' ',sep='',end='')
            print()


wieza(6)
print()
wieze([2,1,3,5])
