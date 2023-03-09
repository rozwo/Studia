#szyfr cezara
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

def odszyf(n,k):
    w=""
    k=k%32
    for i in range(len(n)):
        j=0
        while n[i]!=litery[j]:
            j=j+1
        w=w+litery[(j-k+32)%32]
    return w

def czy_szfr(n,s):
    i=0
    while n[0]!=litery[i]:
        i=i+1
    j=0
    while s[0]!=litery[j]:
        j=j+1
    k=(j-i+32)%32
    if zaszyf(n,k)==s:
        return True
    else:
        return False

print(zaszyf('izabela',13),odszyf('śhkłowk',13),czy_szfr('izabela','śhkłowk'))


