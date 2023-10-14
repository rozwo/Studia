from turtle import *
import time

tracer(0,0)
FRAME_RATE = 1/30

pensize(3)

def kwadrat(bok):
    for i in range(4):
        fd(bok)
        rt(90)

def rozeta(N, kat):
    for i in range(N): 
        fd(70)
        rt(kat)
        kwadrat(30)
        lt(kat)
        bk(70)
        rt(360 / N)


D1 = 5
D2 = 6
kat = 0
i=-500
j=-200

while True:
    t0 = time.time()
    clear()
    pu()
    goto(i,j)
    pd()
    rozeta(10, kat)
    kat += D2
    if i<500:
        i=i+5
        j=j+3
    else:
        i=-500
        j=-200
    rt(D1)
    update()
    delta = time.time() - t0
    if delta < FRAME_RATE:
        time.sleep(FRAME_RATE - delta)
        
#time.sleep(seconds)

input()
