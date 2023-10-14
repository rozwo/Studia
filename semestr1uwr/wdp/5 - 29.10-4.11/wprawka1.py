import random
from turtle import *
import numpy as np

tracer(0,0)

def move(x, y):
    penup()
    goto(x,y)
    pendown()

def tarcza_zegara():
    move(0,0)
    for i in range(60):
        if i%5==0:
            x=1
        else:
            x=0
        pensize(1+x)
        pu()
        fd(200-5*x)
        pd()
        fd(10+5*x)
        move(0,0)
        rt(6)
    lt(90)

def wskazowki(g,m):
    move(0,0)   #godzinowa
    pensize(4)
    rt(30*g+m*0.5)
    fd(85)
    lt(30*g+m*0.5)
    move(0,0)   #minutowa
    rt(6*m)
    fd(170)
    lt(6*m)


def zegar(g,m):
    tarcza_zegara()
    wskazowki(g,m)

zegar(int(input('Podaj godz: ')),int(input('Podaj min: ')))

update()

input()
