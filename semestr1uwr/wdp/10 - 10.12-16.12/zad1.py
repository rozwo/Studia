from turtle import *

tracer(0,0)

def koch(bok, n):
    if n==1:
        fd(bok)
    else:
        koch(bok/3, n-1)
        lt(60)
        koch(bok/3, n-1)
        rt(120)
        koch(bok/3, n-1)
        lt(60)
        koch(bok/3, n-1)

def platek(bok, n):
    pu()
    bk(180)
    pd()
    for i in range(3):
        koch(bok, n)
        rt(120)

platek (300,5)

update()
input()
