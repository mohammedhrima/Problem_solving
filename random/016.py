import math

#a, b = [int(x) for x in input("").split()]

a = 3
b = 2

array = [[0 for j in range(a)] for i in range(a)]

for column in array:
    print(column)

print("\nStart\n")

mark = 1

for i in range(1, a + 1):
    for j in range(1, a + 1):
        if math.sqrt(abs(i*i - j*j)) >= b:
            print(">", math.sqrt(abs(i*i - j*j)))
            array[j - 1][i - 1] = mark
            for column in array:
                print(column)
         
mark += 1



print("\n")

for column in array:
    print(column)
