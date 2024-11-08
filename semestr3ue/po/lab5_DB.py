class Student:
    def __init__(self, course, city):
        self.course = course
        self.adres = Adress(city)
        
class Course:
    def __init__(self, name):
        self.name = name

class Adress:
    def __init__(self, city):
        self.city = city
        
python = Course("python") #PZYKŁAD KOMPOZYCJI
s1 = Student(python, "Wrocław") #PRZYKŁAD AGREGACJI

#%%
class Bank_Account:
    def __init__(self, balance = 0, limit = 0, owner = None):
        self.balance = balance
        self.limit = limit
        self.owner = owner
    
    def deposit(self, amount):
        self.balance += amount
   
    def set_owner(self, owner):
        self.owner = owner
        
    def get_owner(self):
        return self.owner
        
    def raport(self):
        print(self.owner, self.balance)

class Owner:
    def __init__(self, name , city):
        self.name = name
        self.city = city
        
    def get_city(self, city):
        return self.city

o1 = Owner("Karol", "Wroclaw")    
b1 = Bank_Account(300, 500, o1)    #PRZYPISUJEMY JEDNEGO WŁASCICIELA DO JEDNEGO KONTA

o2 = Owner("Michał", "Olesnica")   #PRZYPIUJEMY DRUGIEGO WŁASCICELA DO DRUGIEGO KONTA
b2 = Bank_Account(400, 700, o2)      
                                    #W OBYDWU PRZYPADKACH UZYLEM KOMPOZYCJI 
o1 = None
o2 = None                                    
                                    #TERAZ NASZYM ZADANIEM BYŁO ZAMIANA WŁASCICIELI NA KONTACH 
owner_temp = b1.get_owner()
b1.set_owner(b2.get_owner())        #MIMO TEGO ZE USUNELIMY o1 i o2, TO ZAPISALI SIE ONI NA KONTACH BANKOWYCH 
b2.set_owner(owner_temp)













