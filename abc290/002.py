N, K = [int(x) for x in input("").split()]
S1 = input("")
S2 = 'x'*len(S1)

#print(S1)
#print(S2)

limit = 0
for c in range(len(S1)):
    if S1[c] == 'o':
        S2 = S2[0:c] + 'o' + S2[c+1:]
        limit += 1
    if limit == K:
        break

print(S2)