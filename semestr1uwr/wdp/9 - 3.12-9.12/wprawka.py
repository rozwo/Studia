e=[0]
i=0
for w in open('k.txt').readlines():
 if w=="\n":
  i=i+1
  e.append(0)
 else:
  e[i]=e[i]+int(w)
print(max(e))

e.sort()
print(e[len(e)-3]+e[len(e)-2]+e[len(e)-1])
