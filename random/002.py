n = int(input(""))
string = []

while n:
    n -= 1
    str1 = input("")
    lengh = len(str1)
    if lengh > 10:
        str1 = str1[0] + str(lengh - 2) + str1[-1]
    string.append(str1)

for str2 in string:
    print(str2)

    