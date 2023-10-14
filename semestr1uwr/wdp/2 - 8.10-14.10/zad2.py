s=6
for i in range(4,101):
    s=s*i
    l=len(str(s))
    if l==12 or l==13 or l==14 or l==112 or l==113 or l==114:
        print(f'{i}! ma {l} cyfr')
    elif l%10==2 or l%10==3 or l%10==4:
        print(f'{i}! ma {l} cyfry')
    else:
        print(f'{i}! ma {l} cyfr')

