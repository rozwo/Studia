x=input('Podaj x: ')
k=0
for i in range(len(x)):
    if x[i] not in x[:i]:
        k=k+1
print(k)
