class Student:
    def __init__(self, srednia):
        self.srednia = srednia
        self.__adres = " "

    def set_srednia(self, avg):
        self.srednia = avg

    def get_srednia(self):
        return self.srednia

    def play(self):
        pass

    def learn():
        print("hura uczę się")


s1 = Student(3)
s1.srednia = 44
s1.set_srednia(44)
# s1.set_srednia(s1, 44)

x = s1.srednia

x = s1.get_srednia()
# x = s1.get_srednia(s1)

Student.get_srednia(s1)
# s1.learn()
# s1.leanr(s1)
Student.learn()


s1._Student__adres
