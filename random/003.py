n = int(input(""))
problems = [0]*n
i = 0

while i < n:
    intput_ = input("")
    problems[i] = [int(j) for j in intput_.split()]
    i += 1
    
total = 0
for x in range(n):
    tmp = 0
    for y in range(3):
        tmp += problems[x][y]
    if tmp > 1:
        total += 1

print(total)
