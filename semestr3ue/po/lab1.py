print("wyswietlam i:")
for i in range(10):
    print(i)

#%%
print("wyswietlam x:")
for x in range(10):
    print(x)
# shift enter i robi sie tylko ta komorka w ktorej jestem
#%%
y=1
s=0
while y<=100:
    s+=y
    y+=1
print(s)
#%%
suma=0
for i in range(101):
    suma+=i
print(suma)
#%%
#suma=(a1+an)*n/2
print((1+100)*50)
#%%
y=1
s=0
while s<=1000:
    y+=1
    s+=y
y-=1
print(y)
#sprawdzenie:
suma=0
for i in range(1,y+1,1):
    suma+=i
print(suma)
#%%
a=4
b=7
c=5
if a>b and b>c:
    print(f"najwieksza {a}, srednia {b}, najmniejsza {c}")
elif a>c and c>b:
    print(f"najwieksza {a}, srednia {c}, najmniejsza {b}")
elif b>a and a>c:
    print(f"najwieksza {b}, srednia {a}, najmniejsza {c}")
elif b>c and c>a:
    print(f"najwieksza {b}, srednia {c}, najmniejsza {a}")
elif c>a and a>b:
    print(f"najwieksza {c}, srednia {a}, najmniejsza {b}")
else:
    print(f"najwieksza {c}, srednia {b}, najmniejsza {a}")

#%%
