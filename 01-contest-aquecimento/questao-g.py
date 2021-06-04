from math import floor

b = int(input())
g = int(input())

f = floor(g / 2) - b

if (f == 0) or (b > floor(g / 2)):
    print('Amelia tem todas bolinhas!')
else:
    print(f'Faltam {f} bolinha(s)')