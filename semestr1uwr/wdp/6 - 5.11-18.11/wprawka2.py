from turtle import *

tracer(0,0)

colors = {
   'r' : 'red', 
   'g' : 'green', 
   'b' : 'blue',
   'y' : 'yellow',
   'o' : 'orange', 
}

dane_o_rysunku = ['bobby' + 'bobby'+ 'bobby', 'rybogryby', 'grrrrrry', 'yo' * 10] * 2

def move(x, y):
    penup()
    goto(x,y)
    pendown()

def kwadrat(kolor):
    begin_fill()
    fillcolor(colors[kolor])
    for i in range(4):
        fd(30)
        rt(90)
    end_fill()   
  
p=400
p2=40
kat=360/len(dane_o_rysunku)
pu()
circle(p,-45)
pd()
for i in range(len(dane_o_rysunku)):
    move(0,0)
    pu()
    fd(p)
    circle(p,-kat)
    pd()
    kacik=360/len(dane_o_rysunku[i])
    pu()
    circle(p2,180)
    pd()
    for e in dane_o_rysunku[i]:
        kwadrat(e)
        pu()
        circle(p2,-kacik)
        pd()

update()
input()
