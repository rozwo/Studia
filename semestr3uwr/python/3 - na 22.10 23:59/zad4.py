from collections import deque
# zakladam ze liczby sa z przedzialu [-999999,999999]

liczby={
    "tysiąc":1000,
    "dziewięćset":900,
    "osiemset":800,
    "siedemset":700,
    "sześćset":600,
    "pięćset":500,
    "czterysta":400,
    "trzysta":300,
    "dwieście":200,
    "sto":100,
    "dziewięćdziesiąt":90,
    "osiemdziesiąt":80,
    "siedemdziesiąt":70,
    "sześćdziesiąt":60,
    "pięćdziesiąt":50,
    "czterdzieści":40,
    "trzydzieści":30,
    "dwadzieścia":20,
    "dziewiętnaście":19,
    "osiemnaście":18,
    "siedemnaście":17,
    "szesnaście":16,
    "piętnaście":15,
    "czternaście":14,
    "trzynaście":13,
    "dwanaście":12,
    "jedenaście":11,
    "dziesięć":10,
    "dziewięć":9,
    "osiem":8,
    "siedem":7,
    "sześć":6,
    "pięć":5,
    "cztery":4,
    "trzy":3,
    "dwa":2,
    "jeden":1,
    "zero":0
}

def slowa_w_liczby(L):
    lista = deque()
    for tekst in L:
        x = 0
        z = 1
        slowa = tekst.split()
        for s in slowa:
            if s == "minus":
                z *= -1
            elif s == "tysięcy" or s == "tysiące":
                x *= 1000;
            else:
                x += liczby[s]
        x *= z
        lista.append(x)
    return lista

# print(slowa_w_liczby(["trzydzieści tysięcy dwadzieścia cztery","szesnaście"]))
# print(slowa_w_liczby(["sto dwadzieścia trzy", "osiemset piętnaście", "trzydzieści tysięcy dwieście"]))

def sortuj_liste_liczb(L):
    pom=slowa_w_liczby(L)
    n = len(L)
    while n > 1:
        zamien = False
        for l in range(0, n-1):
            if pom[l] > pom[l+1]:
                pom[l], pom[l+1] = pom[l+1], pom[l]
                L[l], L[l+1] = L[l+1], L[l]
                zamien = True   
        n -= 1
        if zamien == False:
            break
    # print(list(pom))
    return L

# print(sortuj_liste_liczb(["sto dwadzieścia trzy", "trzydzieści tysięcy dwieście", "osiemset piętnaście"]))
# print(sortuj_liste_liczb(["pięćdziesiąt tysięcy sto jedenaście", "dwanaście", "tysiąc siedemset trzydzieści sześć", "czterysta pięćdziesiąt pięć", "dziewięćdziesiąt tysięcy", "dwieście tysięcy dwa", "trzy"]))
# print(sortuj_liste_liczb(["zero", "minus pięćdziesiąt tysięcy sto jedenaście", "dwanaście", "tysiąc siedemset trzydzieści sześć", "czterysta pięćdziesiąt pięć", "dziewięćdziesiąt tysięcy", "dwieście tysięcy dwa", "trzy"]))
