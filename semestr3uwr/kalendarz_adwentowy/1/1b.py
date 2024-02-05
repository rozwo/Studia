suma=0
def slowa_cyfry(s):
    cyfry={
        "one" : 1,
        "two" : 2,
        "six" : 6,
        "four" : 4,
        "five" : 5,
        "nine" : 9,
        "three" : 3,
        "seven" : 7,
        "eight" : 8
    }
    i=0
    while i<len(s):
        if s[i] in "otfsen":
            if i+4<len(s):
                if s[i:i+4] in cyfry:
                    s[i:i+4]=cyfry[s[i:i+4]]
            elif i+3<len(s):
                if s[i:i+3] in cyfry:
                    s[i:i+3]=cyfry[s[i:i+3]]
            elif i+2<len(s):
                if s[i:i+4] in cyfry:
                    s[i:i+4]=cyfry[s[i:i+4]]
            else:
                i+=1
        else:
            i+=1
    return s

for s in open('/home/roo/Dokumenty/studia/semestr3uwr/kalendarz_adwentowy/1/puzzle.txt').readlines():
    s=slowa_cyfry(s)
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