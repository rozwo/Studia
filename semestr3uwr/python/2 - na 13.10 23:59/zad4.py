from random import choice

def uprosc_zdanie(tekst, dl_slowa, liczba_slow):
    w = tekst.split()
    for s in w:
        if len(s) > dl_slowa:
            w.remove(s)
    while len(w) > liczba_slow:
        usun_losowy = choice(w)
        w.remove(usun_losowy)
    return " ".join(w)



tekst = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje się ścianą podziałową inicjowaną \
w płaszczyźnie maksymalnej."
# print(uprosc_zdanie(tekst, 10, 5))
print(uprosc_zdanie(open('lalka-tom-pierwszy.txt').read(),8,34))