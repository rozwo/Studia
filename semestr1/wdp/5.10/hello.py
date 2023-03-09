a=int(input('Podaj a: '))
b=int(input('Podaj b: '))
c=int(input('Podaj c: '))

delta=b*b-4*a*c

if delta<0:
    print('nie ma rozwiazan')
elif delta==0:
    print('x=',-b/2*a)
else:
    print('x1=',(-b-delta**0.5)/(2*a))
    print('x2=',(-b+delta**0.5)/(2*a))

for i in range(0,10,2):
    print(f'pozdro {i}')


