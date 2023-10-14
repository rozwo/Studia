from turtle import *

kolory=['yellow','green','blue','red','black']

def move(x, y):
    penup()
    goto(x,y)
    pendown()

def kwadrat(bok,kolor):
    begin_fill()
    fillcolor(kolor)
    for i in range(4):
      fd(bok)
      rt(90)
    end_fill()
    
def murek(s,bok):
    i=0
    for a in s:
        if a == 'f':
            fd(bok)
        elif a == 'b':
            bk(bok)       
        elif a == 'l':
            lt(90)
        elif a == 'r':
           rt(90)
        elif a=='k':
            kwadrat(bok,kolory[i%5]) 
            i=i+1 

def kwadracior(s):
    tekst=""
    for i in range(s):
        for j in range(s):
            tekst=tekst+'kf'
        tekst=tekst+'rfr'+'f'*s+'rr'
    return tekst

def kwadracik(s):
    tekst=""
    for i in range(4):
        tekst=tekst+'kf'*(s)+'r'
    return tekst

def spirala(s):
    tekst=''
    N = 1
    for j in range(s):
        if j%4==1:
            for i in range(N):
                tekst=tekst+'lfrk'
        elif j%4==2:
            for i in range(N):
                tekst=tekst+'fk'
        elif j%4==3:
            for i in range(N):
                tekst=tekst+'rflk'
        else:
            for i in range(N):
                tekst=tekst+'llfrrk'
        N=j
    return tekst


ht()

tracer(0,0)
move(-200,200)
murek(kwadracik(19),10) 
move(-200,-50)
murek(kwadracior(19),10)    
move(200,0)
murek(spirala(20),10)
update()

input()

