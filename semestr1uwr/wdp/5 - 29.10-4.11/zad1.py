import random
from turtle import *
import numpy as np

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
  
speed('fastest')    

kolor1 = np.array([1,1,0.5])
kolor2 = np.array([1,0.1,0.6])

N = 1
BOK = 10
ile=0
for j in range(20):
    if j%4==1:
        for i in range(N):
            alfa = ile / 210
            mieszanka = (1-alfa) * kolor1 + alfa * kolor2
            lt(90)
            fd(BOK)
            rt(90)
            kwadrat(BOK, mieszanka)
            ile=ile+1
    elif j%4==2:
        for i in range(N):
            alfa = ile / 171
            mieszanka = (1-alfa) * kolor1 + alfa * kolor2
            fd(BOK)
            kwadrat(BOK, mieszanka)
            ile=ile+1
    elif j%4==3:
        for i in range(N):
            alfa = ile / 171
            mieszanka = (1-alfa) * kolor1 + alfa * kolor2
            rt(90)
            fd(BOK)
            lt(90)
            kwadrat(BOK, mieszanka)
            ile=ile+1
    else:
        for i in range(N):
            alfa = ile / 171
            mieszanka = (1-alfa) * kolor1 + alfa * kolor2
            lt(180)
            fd(BOK)
            rt(180)
            kwadrat(BOK, mieszanka)
            ile=ile+1
    N=j

update()
input()
