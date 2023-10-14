litery="aąbcćdeęfghijklłmnńoóprsśtuwyzźż"

def ceasar(n,k):
    w=""
    k=k%32
    for i in range(len(n)):
        j=0
        while n[i]!=litery[j]:
            j=j+1
        w=w+litery[(j+k)%32]
    return w

print(ceasar('śhkłowk',19))
