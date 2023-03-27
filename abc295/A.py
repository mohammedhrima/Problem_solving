N = int(input(""))
string1 = input("").split()

string2 = ["and", "not", "that", "the", "you"]

for sub in string1:
    if sub in string2:
        print("Yes")
        quit()
print("No")

