
contest, solve = [int(x) for x in input("").split()]

problems = [int(x) for x in input("").split()]
solved = [int(x) for x in input("").split()]

result = 0
for x in solved:
    result += problems[x - 1]
print(result)
