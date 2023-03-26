n = int(input())
array = [int(x) for x in input().split()]

paired = set()
pairs = 0

for i in range(n):
    if i not in paired:
        for j in range(i+1, n):
            if j not in paired and array[i] == array[j]:
                paired.add(i)
                paired.add(j)
                pairs += 1
                break

print(pairs)
