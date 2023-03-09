from duze_cyfry import daj_cyfre

x=input('Podaj liczbe: ')
z=[]
r=[]
d=[]
t=[]
c=[]

for i in x:
    y=daj_cyfre(int(i))
    z.append(y[0])
    r.append(y[1])
    d.append(y[2])
    t.append(y[3])
    c.append(y[4])

print(' '.join(z))
print(' '.join(r))
print(' '.join(d))
print(' '.join(t))
print(' '.join(c))
