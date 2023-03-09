#wprawka7dabi

from collections import defaultdict as dd

przedmiot = 'nieznany'

dziennik = dd(lambda : dd(list))

def sortowanie(t):
    for i in range(len(t)):
        j=1
        while j<len(t)-i:
            if t[j-1][1]<t[j][1]:
                t[j-1],t[j]=t[j],t[j-1]
            j=j+1
    return t

for x in open('dziennik.txt'):
    L = x.split()
    if len(L)<1:
        continue
    if L[0].lower() == 'przedmiot:':
        przedmiot = ' '.join(L[1:])
    else:
        if len(L) != 2: continue
        osoba = L[0]
        oceny = [int(n) for n in L[1].split(',')]
            
        dziennik[przedmiot][osoba] += oceny    
        
osoby = {o for p in dziennik for o in dziennik[p]}

print('Świadectwo')
for o in osoby:
    print ('UCZEŃ:', o)
    for p in dziennik:
        oceny = dziennik[p][o]
        if oceny:
            print ('   ',p,int((sum(oceny) / len(oceny))+0.5),'ŚREDNIA=', sum(oceny) / len(oceny))
    print ()
'''
print('Ranking przedmiotow')
for p in dziennik:
    print ('przedmiot:', p)
    r=[]
    for o in osoby:
        oceny = dziennik[p][o]
        if oceny:
            r.append([o,sum(oceny)/len(oceny)])
    r=sortowanie(r)
    for i in range(len(r)):
        print('   ',r[i][0],'ŚREDNIA=',r[i][1])
    print ()
'''
print('Ranking')
r={}
for o in osoby:
    r[o]=0
    ile=0
    for p in dziennik:
        oceny = dziennik[p][o]
        if oceny:
            r[o]=r[o]+(int((sum(oceny) / len(oceny))+0.5))
        ile=ile+1
    r[o]=r[o]/ile
print(sorted(r,key= lambda x:r[x],reverse = True))
print()

