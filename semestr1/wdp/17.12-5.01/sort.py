def sortowanie(t):
    for i in range(len(t)):
        j=1
        while j<len(t)-i:
            if len(t[j-1])<len(t[j]):
                t[j-1],t[j]=t[j],t[j-1]
            j=j+1
    return t

p=['lal','l','lalalalala','ala','kaasaiewoayrammxn']
print(sortowanie(p))
