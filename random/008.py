str1 = input("")
str2 = input("")

for x, y in zip(str1, str2):
    x.lower() < y.lower() and print(-1) 
    x.lower() > y.lower() and print(1)
    if x.lower() != y.lower():
        exit()
print(0)
