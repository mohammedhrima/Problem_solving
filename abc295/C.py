
if __name__ == "__main__":
    N = int(input(""))
    array = list(map(int, input("").split()))
    array.sort()
    res = 0
    i = 0
    while i < N - 1:
        if array[i] == array[i + 1]:
            i += 1
            res += 1
        i += 1

    print(res)
