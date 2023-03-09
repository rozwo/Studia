a=[1,0,0,1,1,0,1,1]
b=[1,0,0,1]
w=[0]
if len(a)>=len(b):
    w=w+a
    for i in range(len(b)):
        w[len(a)-i]=w[len(a)-i]+b[len(b)-i-1]
else:
    w=w+b
    for i in range(len(a)):
        w[len(b)-i]=w[len(b)-i]+a[len(a)-i-1]
i=len(w)-1
while i>0:
    if w[i]==2:
        w[i-1]=w[i-1]+1
        w[i]=0
    i=i-1
if w[0]==0:
    w=w[1:]

print(w)
