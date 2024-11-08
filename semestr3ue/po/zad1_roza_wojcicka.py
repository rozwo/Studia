# 1 ZADANIE DOMOWE

def tax(taxable_amount, rate = 20):
    return taxable_amount*rate/100

# utworzyć nową funkcję (nie zmieniając funkcji tax)
# wyliczającą podatek w zależności od kwoty:
# I próg: do 120 000 zł
# 12%*(podstawa opodatkowania) minus kwota zmniejszająca podatek 3 600 zł
# II próg: ponad 120 000 zł
# 32%*nadwyżka ponad 120 000 zł + 10 800 zł
# funkcję utworzyć przez wrappera i przez dekorator


def tax_wrapper(func):
    def wrapper(tax_base):
        if tax_base <= 120000:
            return func(tax_base,12) - 3600
        else:
            return func((tax_base - 120000),32) + 10800
    return wrapper


calculate_tax=tax_wrapper(tax)
print(calculate_tax(80000))
print(calculate_tax(200000))

#%% wersja z dekoratorem

def tax_wrapper(func):
    def wrapper(tax_base):
        if tax_base <= 120000:
            return func(tax_base,12) - 3600
        else:
            return func((tax_base - 120000),32) + 10800
    return wrapper

@tax_wrapper
def tax(taxable_amount, rate = 20):
    return taxable_amount*rate/100


print(tax(80000))
print(tax(200000))
