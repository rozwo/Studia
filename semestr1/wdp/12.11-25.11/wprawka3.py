def fragmenty(slowo):
    x=0
    L=[]
    for i in open('lalka-tom-pierwszy.txt').read().split():
        if i[0].lower()==slowo[x]:
            L.append(i)
            x=x+1
        else:
            x=0
            L=[]
        if x==len(slowo):
            print(slowo)
            print(' '.join(L))
            L=[]
            x=0

for slowo in open('popularne_slowa.txt').read().split():
    if len(slowo)>4 and len(slowo)<11:
        fragmenty(slowo)

