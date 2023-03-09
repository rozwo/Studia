from random import *
from turtle import *
import numpy as np
from duze_cyfry import daj_cyfre

tracer(0,0)


def move(x, y):
    penup()
    goto(x,y)
    pendown()

def kwadrat(bok, kolor):
    begin_fill()
    kolor=[float(x) for x in kolor]
    fillcolor(kolor)
    for i in range(4):
        fd(bok)
        rt(90)
    end_fill()   
  

bok = 10

n=input('Podaj liczbe: ')
move(-300,0)
for c in n:
    kolor=np.array([randrange(0,10)/10,randrange(0,10)/10,randrange(0,10)/10])
    y=daj_cyfre(int(c))
    for i in range(5):
        for j in range(5):
            if y[i][j]=='#':
                kwadrat(bok, kolor)
                pu()
                fd(bok)
                pd()
            else:
                pu()
                fd(bok)
                pd()
        pu()
        rt(90)
        fd(bok)
        rt(90)
        fd(bok*5)
        rt(180)
        pd()
    pu()
    fd(bok*6)
    lt(90)
    fd(bok*5)
    rt(90)
    pd()

    

update()
input()
