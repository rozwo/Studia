def dhondt(licz_glosow,licz_miejsc):
    glosy=0
    wyniki={}
    lg={}
    for k in licz_glosow:
        glosy=glosy+licz_glosow[k]
    for k in licz_glosow:
        if licz_glosow[k]/glosy>=0.05:
            wyniki[k]=0
    for k in licz_glosow:
        lg[k]=licz_glosow[k]
    licz=0
    # print(lg)
    # print(wyniki)
    while licz<licz_miejsc:
        klucz=max(lg, key=lg.get)
        wyniki[klucz]=wyniki[klucz]+1
        licz=licz+1
        lg[klucz]=licz_glosow[klucz]/(wyniki[klucz]+1)
        # print(lg)
        # print(wyniki)
    return wyniki



wybory={"A": 730,
        "D": 70,
        "B": 310,
        "C": 490}
print(dhondt(wybory,8))

wybory2={"A": 720,
        "B": 100,
        "C": 680}
print(dhondt(wybory2,8))

wybory3={"A": 720,
        "B": 110,
        "C": 60,
        "D": 340}
print(dhondt(wybory3,7))
