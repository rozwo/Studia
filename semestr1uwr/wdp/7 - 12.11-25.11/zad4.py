def podziel(slowo):
    L=[]
    s=''
    for i in range(len(slowo)):
        if slowo[i]==' ':
            if s!='':
                L.append(s)
                s=''
        else:
            s=s+slowo[i]
    return L

print(podziel('        Ala   ma   kota  '))

