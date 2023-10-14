import random
from turtle import *

tracer(0,1)
pensize(2)

def kwadrat(bok):
    for i in range(4):
        fd(bok)
        rt(90)
def move(a,b):
    pu()
    goto(a,b)
    pd()

def rozeta(b):
    p=1
    for i in range(8):
        move(-i*2-p,i*2+p)
        kwadrat(b+i*4+2*p)
        p=p*2
        
rozeta(40)

input()


