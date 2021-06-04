amount = int(input())
numbers_par = []
numbers_imp = []

for _ in range(amount):
    number = int(input())
    if number % 2 == 0:
        numbers_par.append(number)
    else:
        numbers_imp.append(number)

numbers_par.sort()
numbers_imp.sort(reverse=True)
all_numbers = numbers_par + numbers_imp

for number in all_numbers:
    print(number)
