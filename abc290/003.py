N,K = [int(x) for x in input("").split()]

A = [int(x) for x in input("").split()]

mex = 0
s = set
for i in range(N):
    if i not in A:
        mex = i
        break

if mex < K:
    print(mex)
else:
    print(K)