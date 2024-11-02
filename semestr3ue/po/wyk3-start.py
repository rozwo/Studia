def hello():
    print("hello")


hello()

# %%%


def hello(name):
    print(f"hello {name}")


hello("john")

# %%


def greetings(func):
    print("start greeting")
    func()


greetings(hello)

# %%


def greetings():
    print("start greetings")

    def hello():
        print("hello")

    return hello


x = greetings()
x()

y = greetings()
y()

# %%


def hello():
    print("hello")


def hello_2():
    print("hello _2")


def greetings_name(hello_fun):

    def wrapper(name):
        hello_fun()
        print(name)

    return wrapper


new_hello = greetings_name(hello)
new_hello("Tomek")


hello = greetings_name(hello)

# %%


def greetings_name(hello_fun):

    def wrapper(name):
        hello_fun()
        print(name)

    return wrapper


@greetings_name
def hello():
    print("hello")


hello("tomek")
