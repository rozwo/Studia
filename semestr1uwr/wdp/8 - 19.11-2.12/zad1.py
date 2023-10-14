from random import *
from turtle import *

tracer(0,0)

bok = 2

def move(x, y):
    penup()
    goto(x,y)
    pendown()

def kwadrat(kolor):
    begin_fill()
    colormode(255)
    fillcolor(kolor)
    pencolor(kolor)
    for i in range(4):
        fd(bok)
        rt(90)
    end_fill()   

move(0,0)
j=0
for wiersz in open('niespodzianka.txt').readlines():
    move(0,200-bok*j)
    L=wiersz.split()
    for i in range(len(L)):
        L[i]=eval(L[i])
    for k in L:
        kwadrat(k)
        fd(bok)
    j=j+1
    

update()
input()

