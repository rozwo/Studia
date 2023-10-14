pol=list(open('popularne_slowa.txt').read().split())
imie=input('Imie: ')
nazwisko=input('Nazwisko: ')
nazwa=imie.lower()+nazwisko.lower()

def slownik(slowo):
    literki={}
    for l in slowo:
        if l not in literki:
            literki[l]=0
        literki[l]=literki[l]+1
    return literki

def czy_ukladane(w,h):
    word=slownik(w)
    hand=slownik(h)
    #zapozyczone z pl.python.org od nuncjo
    return all(x if x in hand.keys() and hand[x]>=word[x] else False for x in word.keys())

def dobre(slowo):
    if czy_ukladane(slowo,nazwa):
        return True
    return False


polskie=[]
for e in pol:
    if dobre(e):
        polskie.append(e)

for i in range(len(polskie)):
    if dobre(polskie[i]):
        j=i+1
        while j<len(polskie):
            if dobre(polskie[j]):
                if len(polskie[i]+polskie[j])==len(nazwa):
                    s=slownik(polskie[i]+polskie[j])
                    n=slownik(nazwa)
                    if all(x if x in n.keys() and n[x]==s[x] else False for x in s.keys()):
                        print(polskie[i],' ',polskie[j])
            j=j+1
