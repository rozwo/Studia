###
# Róża Wójcicka
# lista 1: zadanie 3
# python3 ulamki.py
# Python 3.8.10
###

#na poczatku w t nie ma elementow 
t=[]
#t na poczatku zawsze jest puste wiec wartosc pocz i kon zaraz sie zmieni na pozadana
# ale deklaruje je globalnie zeby korzystac z nich pozniej
pocz=0
kon=0

def dodaj(t,p,w):
    global pocz
    global kon
    if t==[]:   #przy dodawaniu pierwszego elementu do t nadaje wartosc poczatkowa pocz i kon
        t.append(w)
        pocz=p
        kon=p
    elif p>kon: #gdy dodaje elementy do koncza t
        for i in range(p-kon-1):
            t.append(0)
        t.append(w)
        kon=p
    elif p<pocz:    #gdy dodaje elementy do poczatku t
        for i in range(pocz-p-1):
            t[0:0]=0
        t[0:0]=w
        pocz=p
    else:       #gdy dodaje wartosc elementu ktory juz jest w t (zmieniam jego wartosc)
        t[p-pocz]=w

#t w pythonie jest numerowana od 0 wiec funkcja jest potrzebna zeby odczytac wartosc elementu o ustalonym indeksie
def indeks(t,p):
    return (t[p-pocz] if pocz<=p and p<=kon else 'w t nie ma elementu o takim indeksie')

#wypisuje t
def show(t):
    print(t)

##########################################
#testowanie dzialania
show(t)
dodaj(t,-17,22.2)
show(t)
dodaj(t,1,1.75)
show(t)
dodaj(t,8,-4)
show(t)
dodaj(t,11,3)
show(t)
dodaj(t,-9,17)
show(t)
dodaj(t,15,58)
show(t)
dodaj(t,12,-0.125)
show(t)
print(indeks(t,8))
print(indeks(t,2))
print(indeks(t,-3))
print(indeks(t,-9))
