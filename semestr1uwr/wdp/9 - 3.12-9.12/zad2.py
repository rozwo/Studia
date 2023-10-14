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
'''
    for e in word:
        if e in hand:
            if word[e]>hand[e]:
                return False
        else:
            return False
    return True
'''

print(czy_ukladane('ala','sala'))
