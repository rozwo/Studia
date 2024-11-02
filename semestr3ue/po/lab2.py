def compere_number(a,b):
    if a>b:
        return a
    return b
    
result = compere_number
(10,11)

#%%
def ones(x):
    print('1'*x)

def ones2(x):
    for i in range(x):
        print("1", end="")
    
ones(100)
ones2(100)

#%%
def matrix(m,n):
    for i in range(m):
        for j in range(n):
            print("1", end=" ")
        print()

matrix(5,10)

#%%
def identity_matrix(s):
    for i in range(s):
        for j in range(s):
            if i==j:
                print("1", end=" ")
            else:
                print("0", end=" ")
        print()
        
identity_matrix(5)

#%%
def squere_area(side_a):
    return side_a*side_a
    
def ractangle_area(side_a, side_b):
    return side_a*side_b

print(squere_area(5)," i ",ractangle_area(4,5))

def area(side_a, side_b = None):        #side_a musi być, side_b może ale nie musi
    if side_b == None:
        return squere_area(side_a)
    return ractangle_area(side_a, side_b)

print(area(4, 6), " i ", area(5))

def compare_area(a,a2,b=None,b2=None):
    return compere_number(area(a,b), area(a2,b2))

print(compare_area(4,3))
print(compare_area(4,5,6))
print(compare_area(4,5,b2=6))
print(compare_area(4,5,9,6))

#%%








