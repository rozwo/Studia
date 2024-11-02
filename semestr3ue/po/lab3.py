import random
# x=random.randint(0,10)
# print(x)

def bin_coding(length):
    for i in range(length):
        print(random.randint(0,1),end=" ")

def dec_coding(length):
    for i in range(length):
        print(random.randint(0,9),end=" ")
    
def octal_coding(length):
    for i in range(length):
        print(random.randint(0,7),end=" ")

# bin_coding(20)
# dec_coding(20)
# octal_coding(20)

def protocol(coding,length):
    print("START", end=" ")
    coding(length)
    print("END")

protocol(bin_coding, 20)
protocol(dec_coding, 20)
protocol(octal_coding, 20)

#%%
def good_morning():
    print("Good morning",end="")

def good_afternoon():
    print("Good afternoon",end="")

def good_evening():
    print("Good evening",end="")

def greetings(time):
    time=time%24
    if 0<=time<=11:
        good_morning()
    elif 12<=time<=18:
        good_afternoon()
    else:
        good_evening()
        
def greetings_de(time):
    time=time%24
    if 0<=time<=11:
        print("Guten Morgen",end="")
    elif 12<=time<=18:
        print("Guten Tag",end="")
    else:
        print("Guten Abend",end="")

# greetings(9)
# greetings(15)
# greetings(23)
# greetings(158)

def greeting_wrapper(func):
    def wrapper(name,time):
        func(time)
        print(" "+name)
    return wrapper
    
# new_function=greeting_wrapper(greetings)
# new_function("John",12)

# new_function2=greeting_wrapper(greetings_de)
# new_function2("Klaus",22)

# DEKORATORY
greetings_de = greeting_wrapper(greetings_de)
# to to samo co
@greeting_wrapper
def greetings_de(time):
    time=time%24
    if 0<=time<=11:
        print("Guten Morgen",end="")
    elif 12<=time<=18:
        print("Guten Tag",end="")
    else:
        print("Guten Abend",end="")


def greeting_name(func,name):
    def wrapper(time):
        func(time)
        print(" "+name)
    return wrapper

greeting_tom = greeting_name(greetings, "Tom")
greeting_tom(13)
greeting_tom(3)
greeting_tom(23)

#%%
# 1 ZADANIE DOMOWE

def tax(taxable_amount, rate =20):
    return taxable_amount*rate/100




