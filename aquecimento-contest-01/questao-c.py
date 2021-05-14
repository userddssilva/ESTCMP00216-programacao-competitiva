n = int(input())

for _ in range(n):
    dict_products = {}
    m = int(input())
    total = 0

    for _ in range(m):
        product_name, price = input().split(' ')
        dict_products[product_name] = float(price)

    p = int(input())
    
    for _ in range(p):
        product_name, amount = input().split(' ')
        total += dict_products[product_name] * int(amount)

    print('R$ %.2f'%total)