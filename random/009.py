n = int(input())
numbers = list(map(int, input().split()))

even = []
odd = []

for i in range(n):
    if numbers[i] % 2 == 0:
        even.append(numbers[i])
    else:
        odd.append(numbers[i])

even.sort(reverse=True)
odd.sort(reverse=True)

res = -1
if len(even) >= 2:
    res = max(res, even[0] + even[1])
if len(odd) >= 2:
    res = max(res, odd[0] + odd[1])

print(res)
