def fibmod(k,r):
    if k<=1:
        return 1%r
    return (fibmod(k-1,r)+fibmod(k-2,r))%r

k=int(input('k: '))
print(fibmod(k,3))

"""
nie rekurencyjnie
k=int(input('k: '))

def fibmod(k,r):
    f=[]
    f.append(1%r)
    f.append(1%r)
    for i in range(2,k+1):
        f.append((f[i-1]+f[i-2])%r)
    return f[k]

print(fibmod(k,3))
"""
