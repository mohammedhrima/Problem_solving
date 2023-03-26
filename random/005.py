number_of_participants, rank = [int(x) for x in input("").split()]
scores = [] if number_of_participants == 0 else [
    int(x) for x in input("").split()]

total = 0
for x in scores:
    if x > 0 and x >= scores[rank - 1]:
        total += 1

print(total)
