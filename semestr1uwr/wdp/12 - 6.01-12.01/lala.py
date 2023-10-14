from turtle import *
import time

#tracer(0,0)

pensize(3)

def glowa(p):
    circle(p,-100)
    rt(140)
    fd(p)
    rt(130)
    fd(p)
    lt(20)
    x2,y2=pos()
    fd(2*p/3)
    lt(20)
    fd(p)
    rt(130)
    fd(p)
    rt(139)
    circle(p,-75)
    goto(x2,y2)
    rt(199)
    circle(p,-38)
    goto(x2,y2)
    
def kot(p):
    rt(-25)
    begin_fill()
    color("brown")
    x1,y1=pos()
    rt(90)
    fd(2.5*p)
    rt(150)
    circle(1.75*p,-260)
    lt(40)
    circle(3.5*p,-52)
    lt(100)
    glowa(1.25*p)
    end_fill()

kot(50)

#update()
input()
