#zad2zlisty6

def wzaj_odwr(s):
    n=''
    for l in s:
        n=l+n
    return n

pol=set(list(open('popularne_slowa.txt').read().split()))
for s in pol:
    o=wzaj_odwr(s)
    if o in pol:
        if s<o:
            print(s,o)
        
