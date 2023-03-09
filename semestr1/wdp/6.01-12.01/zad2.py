from collections import defaultdict as dd

slownik = dd(lambda : dd(list))

def ppn(slowo):
    w=[]
    i=1
    for l in slowo:
        if l not in slownik:
            slownik[l]=i
            i=i+1
    for l in slowo:
        w.append(str(slownik[l]))
    print('-'.join(w))

s=input('Slowo: ')
ppn(s)
