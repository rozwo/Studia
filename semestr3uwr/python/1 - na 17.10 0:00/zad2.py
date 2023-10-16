def is_palindrom(tekst):
    t = "".join(tekst.lower().split())
    znaki = [",",".",":",";","!","?"]     
    for z in znaki:                        
        t = t.replace(z,"")
    # print(t)
    for i in range(int(len(t)/2)):
        if t[i] != t[len(t)-1-i]:
            return False
    return True

print(is_palindrom("oko"))
print(is_palindrom("rOtOr"))
print(is_palindrom("Kobyła ma mały bok"))
print(is_palindrom("Eine güldne, gute Tugend: Lüge nie!"))
print(is_palindrom("Míč omočím."))