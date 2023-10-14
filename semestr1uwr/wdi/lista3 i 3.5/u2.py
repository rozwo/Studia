k=int(input('Podaj k: '))
n=int(input('Podaj n: '))
w=[]
wynik=0
for i in range(k):
    w.append(0)
if n<0:
    w[0]=1
    wynik=-(2**(k-2))
i=2
while wynik<n and i<k:
    if wynik+2**(k-i-1)<=n:
        wynik=wynik+2**(k-i-1)
        w[i]=1
    i=i+1

print(w)
