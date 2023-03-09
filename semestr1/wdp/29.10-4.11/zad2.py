import random

"""
W tym programie znajduje sie kilka prostych funkcji demonstrujacych operacje na listach.

[!] oznacza, ze w danym miejscu konieczne jest dopisanie (ew. zmiana) istniejacego kodu.

Prawidlowy wynik dzialania programu znajduje sie na stronie KNO
"""

def parzysta(n):
    return True if n%2==0 else False  #[!]

def suma1(L):
    wynik = 0
    for element in L:
        wynik += element
    return wynik
   
def suma2(L):  #[!]
    wynik=0
    for indeks in range(len(L)):
        wynik += L[indeks]
    return wynik
   
def suma_parzystych(L): #[!]
    wynik = 0
    for element in L:
        if parzysta(element):
            wynik += element
    return wynik

def ze_spacjami(n,k):
    s = str(n)
    if len(s) < k:
        s += "_"*(k-len(s))  #[!]
    return s  

def histogram(L):
    for liczba in L:
        print (ze_spacjami(liczba,3)+ "*" * liczba) #[!]

def powieksz_liczby(L):
    for i in range(len(L)):
        L[i]=L[i]+1 #[!] (pass oznacza "nic nie rob")
   
def normalizuj(L):
    sr=suma1(L)/len(L) #[!]
    for i in range(len(L)): #[!]
        L[i]-=sr

def znormalizowana(L): #[!]
    L2=L[:]
    normalizuj(L2)
    return L2

def powiekszone_parzyste_z_zerami(L): #[!]
    wynik = []
    for n in L:
        if parzysta(n):
            wynik.append(n+1)
            wynik.append(0)
        else:
            pass
    return wynik      
   
def madrzejsza(L): #[!]
    madre_slowa = ["istotnie", "zasadniczo", "rudymentalnie", "rustykalnie", "radykalnie", "hej"]
   
    wynik = []
    for i in range(len(L)):
        if len(L[i])>4:
            wynik.append(L[i])
            wynik.append(random.choice(madre_slowa))
    return wynik   

#demonstracja
L = [1,2,3,4,5]

print ("Dla listy " + str(L) + " suma elementow rowna sie")
print (suma1(L))
print (suma2(L))
print ("Jak zsumujemy tylko parzyste, to otrzymamy")
print (suma_parzystych(L))
print ("")         

H = [1,2,3,4,5,6,7,4,8,4,8,2,2,1,10]
print ("Histogram dla listy " + str(H))
histogram(H)
print ("")         

print ("Zaczynamy od " + str(L) + " i zwiekszamy 4 razy")

powieksz_liczby(L); print (L) # raczej nie uzywamy srednikow, ale tu nie moglem sie powstrzymac
powieksz_liczby(L); print (L)
powieksz_liczby(L); print (L)
powieksz_liczby(L); print (L)

L = [1,2,3,4,5]
L2 = L[:]

print ("")         
print ("Zaczynamy od " + str(L2) + " i normalizujemy 3 razy")

normalizuj(L2); print (L2)
normalizuj(L2); print (L2)
normalizuj(L2); print (L2)

print ("Dlaczego ciagle to samo?")

print ("O, i znowu:")

print (znormalizowana(L))
print ("Oczywiscie mamy " + str(L) + " == [1,2,3,4,5]") 

print ("")         
print ("Powiekszamy parzyste, pomijamy nieparzyste i wstawiamy 0 po")         
print (powiekszone_parzyste_z_zerami(L))


print ("Cos madrego na zakonczenie:")         
Dane = "nauka programowania w pythonie wcale nie jest taka trudna".split()
print (" ".join(madrzejsza(Dane)))


