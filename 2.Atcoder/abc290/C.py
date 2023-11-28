N,K = [int(x) for x in input("").split()]
A = [int(x) for x in input("").split()]

i = 0
while i < K:
    if not i in A:
        print(i)
        quit()
    i += 1

print(K)