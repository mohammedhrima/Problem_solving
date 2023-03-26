people, parties = [int(x) for x in input("").split()]

array = [[]]
for x in range(parties):
    array[x] = [int(x) for x in input("").split()]

def includes(arr, n):
    for x in arr:
        if x == n:
            return True
    return False

array1 = [[False] * range(people)]*range(people)

for x in range(people):
    for y in range(people):
        if x == y:
            array1[x][y] = True
