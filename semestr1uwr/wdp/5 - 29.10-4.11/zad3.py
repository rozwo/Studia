import random

def randperm(n):
    return random.sample(range(0,n),k=n)

print(randperm(10))
print(randperm(10))
print(randperm(10))

print(randperm(10**6))
