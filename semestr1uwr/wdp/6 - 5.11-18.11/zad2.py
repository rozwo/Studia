from random import *
from turtle import *
import numpy as np

tracer(0,0)

def move(x, y):
    penup()
    goto(x,y)
    pendown()

def krzyzyk(bok, kolor):
    begin_fill()
    kolor=[float(x) for x in kolor]
    fillcolor(kolor)
    rt(45)
    for i in range(4):
        rt(90)
        fd(bok)
        rt(90)
        fd(bok)
        lt(90)
        fd(bok)
    end_fill()
  
  

bok = 16

move(0,0)
lt(90)
kolor1=np.array([randrange(0,10)/10,randrange(0,10)/10,randrange(0,10)/10])
for i in range(36):
    kolor2=np.array([randrange(0,10)/10,randrange(0,10)/10,randrange(0,10)/10])
    mieszanka = 0.5 * kolor1 + 0.5 * kolor2
    pu()
    fd(200)
    pd()
    krzyzyk(bok,mieszanka)
    move(0,0)
    lt(45)
    rt(10)
    kolor1=kolor2
lt(90)

update()
input()
