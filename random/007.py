res = 0
for x in range(int(input(""))):
    str = input("")
    if str.startswith("++") or str.endswith("++"):
        res += 1
    if str.startswith("--") or str.endswith("--"):
        res -= 1

print(res)