peoples, parties = [int(x) for x in input("").split()]

table = [[0 for j in range(peoples)] for i in range(peoples)]
for i in range(peoples):
    for j in range(peoples):
        if i == j:
            table[i][j] = 1

"""print("Table before")
for x in range(peoples):
    print(table[x])"""

if peoples:
    for n in range(parties):
        party = [int(x) for x in input("").split()]
        party = party[1:]
        for x in range(len(party)):
            for y in range(len(party)):
                if x != y:
                    table[party[x] - 1][party[y] - 1] = 1
                    table[party[y] - 1][party[x] - 1] = 1

            #break

"""print("Table after")
for x in range(peoples):
    print(table[x])"""

for x in range(peoples):
    for y in range(peoples):
        if table[x][y] == 0:
            print("No")
            quit()
if peoples:
    print("Yes")
