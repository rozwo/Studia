from losowanie_fragmentow import losuj_fragment

def losuj_haslo(n):
    h=''
    while n-len(h)>5:
        s=losuj_fragment()
        h=h+s
    if n-len(h)==2:
        while len(s)!=2:
            s=losuj_fragment()
        h=h+s
        return h
    elif n-len(h)==3:
        while len(s)!=3:
            s=losuj_fragment()
        h=h+s
        return h
    elif n-len(h)==4:
        while len(s)%2!=0:
            s=losuj_fragment()
        h=h+s
        if len(s)==4:
            return h
        else:
            while len(s)!=2:
                s=losuj_fragment()
            h=h+s
            return h
    else:   #gdy jest 5
        while len(s)==4:
            s=losuj_fragment()
        h=h+s
        if len(s)==3:
            while len(s)!=2:
                s=losuj_fragment()
            h=h+s
            return h
        else:   #jest 2
            while len(s)!=3:
                s=losuj_fragment()
            h=h+s
            return h

for i in range(10):
    print(losuj_haslo(8))
for i in range(10):
    print(losuj_haslo(12))


