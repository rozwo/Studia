polskie=open('popularne_slowa.txt').read().split()
polskie=set(polskie)

def dobre_slowo(slowo):
    for z in "ąćęłńóśżź":
        if z in slowo:
            return False
    return slowo in polskie

d=0
tekst=""
maks=0
najd=""
for i in open('lalka-tom-pierwszy.txt').read().split():
    if dobre_slowo(i):
        tekst=tekst+i+" "
        d=d+len(i)
    else:
        if maks<d:
            maks=d
            najd=tekst
            print(najd)
        d=0
        tekst=""
print(tekst)

