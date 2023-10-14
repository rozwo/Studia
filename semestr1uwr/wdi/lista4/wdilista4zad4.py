#nie dziala
n=int(input('Podaj n: '))
k=int(input('Podaj k: '))
a=[]
for i in range(k):
    a.append(int(input('Podaj liczbe: ')))
p=0
for i in range(k):
    ile=0
    x=n
    while x%a[i]==0:
        x=x/a[i]
        ile=ile+1
    if ile>p:
        p=ile
print(p)
for i in range(k):
    if n%(a[i]**p)==0:
        print(a[i])

