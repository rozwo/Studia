pol=set(list(open('popularne_slowa.txt').read().split()))
polskie=list(open('popularne_slowa.txt').read().split())
litery="aąbcćdeęfghijklłmnńoóprsśtuwyzźż"

def zaszyf(n,k):
    w=""
    k=k%32
    for i in range(len(n)):
        j=0
        while n[i]!=litery[j]:
            j=j+1
        w=w+litery[(j+k)%32]
    return w

dobre=[]
for i in range(len(polskie)):
    w=1
    for a in polskie[i]:
        if a not in litery:
            w=0
    for j in range(32):
        j=j+1
        if w==1:
            if zaszyf(polskie[i],j) in pol:
                dobre.append([polskie[i],zaszyf(polskie[i],j)])

m=0
for i in range(len(dobre)):
    if len(dobre[i][0])>m:
        m=len(dobre[i][0])
for i in range(len(dobre)):
    if len(dobre[i][0])==m:
        print(dobre[i][0],' ',dobre[i][1])

