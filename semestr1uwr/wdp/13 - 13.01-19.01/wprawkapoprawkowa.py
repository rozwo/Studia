from collections import defaultdict as dd
pol=list(open('popularne_slowa.txt').read().split())

def palindrom(n):
    if n==''.join(list(reversed(n))):
        return True
    else:
        return False
        
slownik = dd(list)

for s in pol:
    if len(s) < 3:
        continue
    slownik[s[-3:]].append(s)

n1=""
n2=""
for s1 in pol:
    if len(s1) < 3 or not s1.isalpha():
        continue
    for s2 in slownik[s1[2]+s1[1]+s1[0]]:
        if palindrom(s1+s2) and len(s1+s2)>len(n1+n2):
            n1=s1
            n2=s2
            print(n1,n2)



