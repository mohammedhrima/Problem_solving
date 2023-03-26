N, K = [int(x) for x in input("").split()]
C = [int(x) for x in input("").split()]

res = 0
c = set(C)

print("range is: ", N - K + 2)

for i in range(N):
    
    if i in C:
        res += 1

print(res)

"""
7 3
for i in range(1 , N - K + 2)  # [1 : 6[

5 5
1 <= i <= 

"""
