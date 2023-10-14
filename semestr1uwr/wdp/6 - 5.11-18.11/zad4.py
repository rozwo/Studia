def usun_duplikaty(L):
    wynik=[]
    for e in L:
        if e not in wynik:
            wynik.append(e)
    return wynik

print(usun_duplikaty([1,2,3,1,2,3,8,2,2,2,9,9,4]))
