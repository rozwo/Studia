from turtle import *
import time
import numpy as np

tracer(0,0)
FRAME_RATE = 1/30

def serce(a):
    k=[float(x) for x in a]
    color(k)
    begin_fill()
    pensize(3)
    left(50)
    forward(133)
    circle(50,200)
    right(140)
    circle(50,200)
    forward(133)
    end_fill()

i=-500
j=-200
ile=0
kolor2=np.array([1,0.1,0.6])
kolor=kolor2
kolor1=np.array([1,1,0.5])
while True:
    t0 = time.time()
    clear()
    pu()
    goto(i,j)
    pd()
    serce(kolor)
    if i<500:
        kolor=(1-(ile/300))*kolor1+(ile/300)*kolor2
        i=i+5
        j=j+3
        ile=ile+1
    else:
        i=-500
        j=-200
        kolor=np.array([1,0.1,0.6])
        ile=0
    update()
    delta = time.time() - t0
    if delta < FRAME_RATE:
        time.sleep((FRAME_RATE - delta)*2)
        

input()



