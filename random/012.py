n = int(input())

array = input().split()

correct = ["and", "not", "that", "the", "you"]

for x in range(n):
    if array[x] in correct:
        print("Yes")
        break
else:
    print("No")
