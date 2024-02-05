suma=0
for s in open('/home/roo/Dokumenty/studia/semestr3uwr/kalendarz_adwentowy/1/puzzle.txt').readlines():
    w=0
    i=0
    while w==0 and i<len(s):
        if s[i] in "0123456789":
            suma+=10*int(s[i])
            w=1
        i+=1
    w=0
    i=len(s)-1
    while w==0 and i>-1:
        if s[i] in "0123456789":
            suma+=int(s[i])
            w=1
        i-=1
print(suma)