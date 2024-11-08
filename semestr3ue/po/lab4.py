class Student():
    ile_studentow=0
    def __init__(self,imie,nazwisko,srednia):
        Student.ile_studentow+=1
        self.imie=imie
        self.nazwisko=nazwisko
        if srednia>=2 and srednia<=5:
            self.srednia=srednia
        else:
            print("Zle podana srednia")
            self.srednia=2
    def __str__(self):
        return self.imie + " " + self.nazwisko + " " + str(self.srednia)

# roza=Student("Róża","Wójcicka",4.54)
# marek=Student("Marek","Kalitan",5)
# dominik=Student("Dominik","Bełza",4.79)

# print(roza.imie,roza.nazwisko,roza.srednia,marek.imie,marek.nazwisko,marek.srednia,dominik.imie,dominik.nazwisko,dominik.srednia, sep=" ")
# print(roza,marek,dominik, sep=" ")

# xy=Student("x","y",1)
# print(xy)
# xz=Student("x","z",7)
# print(xz)

def najlepszy_student(s1,s2,s3):
    if s1.srednia>=s2.srednia and s1.srednia>=s3.srednia:
        return s1
    elif s2.srednia>=s1.srednia and s2.srednia>=s3.srednia:
        return s2
    else:
        return s3

# print("Najwyższą srednią ma ",najlepszy_student(roza,dominik,marek))

# print(Student.ile_studentow)

studenci = [Student("Róża","Wójcicka",4.54),Student("Marek","Kalitan",5),Student("Dominik","Bełza",4.79)]
for s in studenci:
    print(s)

#%%

# lista = [2,4,5]
# lista2 = ["ania", "hania"]

# lista2=lista
# lista.append(8)
# print(lista2)

