N = int(input(""))
string = input("")


i = 0
while i < len(string):
    if string[i] == '1':
        break
    i += 1
if i % 2 == 0:
    print("Takahashi")
else:
    print("Aoki")
    