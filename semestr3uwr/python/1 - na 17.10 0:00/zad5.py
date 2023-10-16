def common_prefix(lista_slow):
    # for slowo in lista_slow:
    #     slowo = slowo.lower()
    lista_slow = [slowo.lower() for slowo in lista_slow]
    lista_slow.sort() #alfabetycznie
    # print(lista_slow)
    najpref = ""
    for i in range(len(lista_slow)-3):
        aktpref = ""
        j = 0
        # print(aktpref, lista_slow[i], lista_slow[i+2])
        while j < min(len(lista_slow[i]), len(lista_slow[i+2])) and lista_slow[i][j] == lista_slow[i+2][j]:
            aktpref += lista_slow[i][j]
            j += 1
            # print(aktpref)
        if len(aktpref) > len(najpref):
            najpref = aktpref
    return najpref

lista_slow = ["Cyprian", "cyberotoman", "cynik", "ceniąc", "czule"]
print(common_prefix(lista_slow))
