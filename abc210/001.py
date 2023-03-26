lenght ,limit , normal_price, extra_price = [int(x) for x in input("").split()]

if lenght <= limit:
    print(lenght * normal_price)
else:
    print(limit * normal_price + (lenght - limit) * extra_price)
