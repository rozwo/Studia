def max_sublist_sum(lista):
    maks=sum(lista[0:1])
    a = 0
    b = 0
    for i in range(len(lista)):
        for j in range(i,len(lista)):
            m = sum(lista[i:j+1])
            if m>maks:
                maks=m
                a=i
                b=j
    return (a,b)

# print(max_sublist_sum([8,3,4,2,5,1]))
# print(max_sublist_sum([1,2,3,-4,5,-11,2,-7,9,-1,2]))
# print(max_sublist_sum([-2,-1,-4,0,-1,3]))