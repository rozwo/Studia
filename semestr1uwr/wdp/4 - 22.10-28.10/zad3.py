def usun_w_nawiasach(napis):
    wynik = ''
    x=0
    for i in range(len(napis)):
        if napis[i]=='(':
            x=i
            while napis[x]!=')':
                x=x+1
            x=x+1
        elif i<x:
            continue
        else:
            wynik += napis[i]
    return wynik

    
print (usun_w_nawiasach("Ala ma kota (perskiego)"))  
print (usun_w_nawiasach("Ala ma kota (perskiego) i psa"))  
print (usun_w_nawiasach("Ala ma kota (perskiego) i psa (jacka teriera) i chomika"))  
