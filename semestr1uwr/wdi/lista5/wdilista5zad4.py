maxn=100
def ciag_g(n):
    g=array(maxn)
    g[0]=1
    g[1]=1
    g[2]=1
    for i in range(3,n+1):
        g[i] = g[i-1]+g[i-2]+g[i-3]
    return g[n]

print(ciag_g(5))
