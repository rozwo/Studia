def hiperszczesliwa(liczba):
    liczba=str(liczba)
    if '7777777' in liczba:
        return True
    else:
        return False
#czesc 1!
t={}
for wiersz in open('transakcje.txt').readlines():
    w=wiersz.split()
    if w[0]=='#':
        continue
    elif w[0]=='+':
        if w[1] not in t:
            t[w[1]]=0
        t[w[1]]=t[w[1]]+int(w[2])
    else:
        if w[0] not in t:
            t[w[0]]=0
        t[w[0]]=t[w[0]]-int(w[2])
        if w[1] not in t:
            t[w[1]]=0
        t[w[1]]=t[w[1]]+int(w[2])
najo='nikt'
m=0
osoby={o for o in t}
for o in osoby:
    if t[o]>m:
        m=t[o]
        najo=o
print(najo,m)
#czesc 2!
tekst=str(open('transakcje.txt').read().split())
l=0
while (hiperszczesliwa(hash(tekst+str(l)))==False):
    l=l+1
print(l)
print(hash(tekst+str(l)))
