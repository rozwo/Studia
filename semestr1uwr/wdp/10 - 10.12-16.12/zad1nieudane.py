#drzewo pitagorasa
from turtle import *
import numpy as np
from math import cos
from math import sin

#tracer(0,0)

def kwadrat(bok, kolor):
    begin_fill()
    kolor=[float(x) for x in kolor]
    fillcolor(kolor)
    for i in range(4):
        fd(bok)
        rt(90)
    end_fill()  

def drzewo(n,bok,kat,czy_pierwszy):
    if n!=0:
        kwadrat(bok,np.array([1,1,0.5]))
        penup()
        lt(kat+90)
        fd(bok*cos(kat/360))
        rt(90)
        pendown()
        drzewo(n-1,bok*cos(kat/360),kat,0)
        penup()
        
        pendown()
        drzewo(n-1,bok*sin(kat/360),kat,0)
        
    


n=6
bok=50
kat=20
drzewo(n,bok,kat,1)    

#update()
input()
