def pierwsze_imperatywna(n): # mysle ze szybciej by sie liczyla wersja zakomentowana ale zeby wszedzie bylo mniej wiecej tak samo zrobilam sandardowym sposobem
    p = []
    for l in range(2,n+1):
    # p = [2]
    # for l in range(3,n+1,2):
        czy_pierw = True
        for d in range(2,int(l**0.5)+1):
        # for d in p:
            if l%d == 0:
                czy_pierw = False
                break
        if czy_pierw:
            p.append(l)
    return p

def pierwsze_skladana(n):
    return [l for l in range(2,n+1) if all(l%d != 0 for d in range(2,int(l**0.5)+1))]

def pierwsze_funkcyjna(n):
    def czy_pierwsza(l):
        return all(l%d != 0 for d in range(2,int(l**0.5)+1))
    return list(filter(czy_pierwsza, range(2,n+1)))

# print(pierwsze_imperatywna(20))
# print(pierwsze_skladana(20))
# print(pierwsze_funkcyjna(20))

# pomiar czasu
import timeit
print("n     imperatywna  skladana  funkcyjna")
for n in [100, 200, 300, 400, 500, 600, 700, 800, 900]:
    time_imperatywna = timeit.timeit(lambda: pierwsze_imperatywna(n), number=10)
    time_skladana = timeit.timeit(lambda: pierwsze_skladana(n), number=10)
    time_funkcyjna = timeit.timeit(lambda: pierwsze_funkcyjna(n), number=10)
    print(f"{n}:  {time_imperatywna:.3f}        {time_skladana:.3f}     {time_funkcyjna:.3f}")

# wypisuja sie za kazdym razem inne tabelki dla tych n-ów