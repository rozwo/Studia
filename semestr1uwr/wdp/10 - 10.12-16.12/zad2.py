pol=list(open('popularne_slowa.txt').read().split())
imie=input('Imie: ')
nazwisko=input('Nazwisko: ')
nazwa=imie.lower()+nazwisko.lower()

def slownik(slowo):
    slowo=''.join(sorted(slowo))
    literki={}
    for l in slowo:
        if l not in literki:
            literki[l]=0
        literki[l]=literki[l]+1
    return literki

def czy_ukladane(w,h):
    word=slownik(w)
    hand=slownik(h)
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
            k=j+1
            if dobre(polskie[j]):
                while k<len(polskie):
                    if dobre(polskie[k]):
                        if len(polskie[i]+polskie[j]+polskie[k])==len(nazwa):
                            s=slownik(polskie[i]+polskie[j]+polskie[k])
                            n=slownik(nazwa)
                            if all(x if x in n.keys() and n[x]==s[x] else False for x in s.keys()):
                                print(polskie[i],' ',polskie[j],' ',polskie[k])
                    k=k+1
            j=j+1
