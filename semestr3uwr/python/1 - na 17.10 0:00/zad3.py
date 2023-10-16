def tabliczka(x1, x2, y1, y2, d):
    n = int(((x2-x1)/d)+2)
    m = int(((y2-y1)/d)+2)
    t = [[0] * m for i in range(n)]
    for i in range(1,n):
        t[i][0] = x1 + d*(i-1)
    for i in range(1,m):
        t[0][i] = y1 + d*(i-1)
    for i in range(1,n):
        for j in range(1,m):
            t[i][j] = t[i][0]*t[0][j]
    t[0][0]=""
    # wypisywanie
    for i in range(n):
        maks = 0
        for j in range(m):
            maks = max(len(str(t[i][j])),maks)
        for j in range(m):
            t[i][j] = " "*(maks-len(str(t[i][j]))) + str(t[i][j])
    for j in range(m):
        linia=""
        for i in range(n):
            linia=linia+" "+t[i][j]
        print(linia)

tabliczka(3.0, 5.0, 2.0, 4.0, 1.0)
print()
tabliczka(3.0, 5.0, 2.0, 4.0, 0.5)