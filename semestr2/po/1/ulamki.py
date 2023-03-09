###
# Róża Wójcicka
# lista 1: zadanie 2
# python3 ulamki.py
# Python 3.8.10
###

#najwiekszy wspolny dzielnik
def NWD(l,m):   #l-licznik, m-mianownik, r-reszta z dzielenia
    r=l%m
    if r==0:
        return m
    return NWD(m,r)

#ulamek w postaci uproszczonej
def skracanie_ulamka(u):    #u[0]-licznik, u[1]-mianownik
    if u[1]<0:
        u[0]=u[0]*(-1)
        u[1]=u[1]*(-1)
    n=NWD(u[0],u[1])
    u[0]=u[0]//n
    u[1]=u[1]//n
    return u

#wyswietlanie ulamka
def show(u):
    print('Wartosc ulamka = ',u[0],'/',u[1])



### podstawowe dzialania wersja 1

#dodawanie
def add_ulamkow_1(u1,u2):
    return skracanie_ulamka([(u1[0]*u2[1]+u2[0]*u1[1]),(u1[1]*u2[1])])

#odejmowanie
def sub_ulamkow_1(u1,u2):
    return skracanie_ulamka([(u1[0]*u2[1]-u2[0]*u1[1]),(u1[1]*u2[1])])

#mnozenie
def mult_ulamkow_1(u1,u2):
    return skracanie_ulamka([(u1[0]*u2[0]),(u1[1]*u2[1])])

#dzielenie
def div_ulamkow_1(u1,u2):
    return skracanie_ulamka([(u1[0]*u2[1]),(u1[1]*u2[0])])



### podstawowe dzialania wersja 2

#dodawanie
def add_ulamkow_2(u1,u2):
    u2[0]=u1[0]*u2[1]+u2[0]*u1[1]
    u2[1]=u1[1]*u2[1]
    return skracanie_ulamka(u2)

#odejmowanie
def sub_ulamkow_2(u1,u2):
    u2[0]=u1[0]*u2[1]-u2[0]*u1[1]
    u2[1]=u1[1]*u2[1]
    return skracanie_ulamka(u2)

#mnozenie
def mult_ulamkow_2(u1,u2):
    u2[0]=u1[0]*u2[0]
    u2[1]=u1[1]*u2[1]
    return skracanie_ulamka(u2)

#dzielenie
def div_ulamkow_2(u1,u2):
    pom=u2[0]   #zmienna pomocnicza
    u2[0]=u1[0]*u2[1]
    u2[1]=u1[1]*pom
    return skracanie_ulamka(u2)




##########################################
#testowanie dzialania
l1=int(input('Podaj wartosc licznika pierwszego ulamka '))
m1=int(input('Podaj wartosc mianownika pierwszego ulamka '))
l2=int(input('Podaj wartosc licznika drugiego ulamka '))
m2=int(input('Podaj wartosc mianownika drugiego ulamka '))
u1=[l1,m1]
u2=[l2,m2]

show(u1)
show(u2)
show(skracanie_ulamka(u1))
show(skracanie_ulamka(u2))

show(add_ulamkow_1(u1,u2))
show(sub_ulamkow_1(u1,u2))
show(mult_ulamkow_1(u1,u2))
show(div_ulamkow_1(u1,u2))

u1=[l1,m1]
u2=[l2,m2]
show(add_ulamkow_2(u1,u2))
u1=[l1,m1]
u2=[l2,m2]
show(sub_ulamkow_2(u1,u2))
u1=[l1,m1]
u2=[l2,m2]
show(mult_ulamkow_2(u1,u2))
u1=[l1,m1]
u2=[l2,m2]
show(div_ulamkow_2(u1,u2))
