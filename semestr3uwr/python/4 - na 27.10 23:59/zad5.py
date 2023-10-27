import random

def czy_dobrze(slowo1, slowo2, operator, slowo3, litery, wynik):
    liczba1=0
    while(len(slowo1)>0):
        i=0
        while(litery[i]!=slowo1[0]):
            i+=1
        liczba1=liczba1*10+int(wynik[i])
        slowo1=slowo1[1:]
    liczba2=0
    while(len(slowo2)>0):
        i=0
        while(litery[i]!=slowo2[0]):
            i+=1
        liczba2=liczba2*10+int(wynik[i])
        slowo2=slowo2[1:]
    liczba3=0
    while(len(slowo3)>0):
        i=0
        while(litery[i]!=slowo3[0]):
            i+=1
        liczba3=liczba3*10+int(wynik[i])
        slowo3=slowo3[1:]
    if operator == '+':
        return liczba1 + liczba2 == liczba3
    elif operator == '-':
        return liczba1 - liczba2 == liczba3
    elif operator == '*':
        return liczba1 * liczba2 == liczba3
    elif operator == '/':
        return liczba1 / liczba2 == liczba3
    else:
        return False

def losuj_permutacje(litery):
    return random.sample("0123456789", len(litery))

def rozw_Kryptarytm(slowo1, slowo2, operator, slowo3):
    litery = []
    s = slowo1 + slowo2 + slowo3
    for l in s:
        if l not in litery:
            litery.append(l)
    while True:
        wynik = losuj_permutacje(litery)
        if czy_dobrze(slowo1, slowo2, operator, slowo3, litery, wynik):
            break
    rozwiazanie = {litery[i]: wynik[i] for i in range(len(litery))}
    return rozwiazanie

result = rozw_Kryptarytm("KIOTO", "OSAKA", '+', "TOKIO")
for litera, cyfra in result.items():
    print(litera, " = ", cyfra)
