H, W = [int(x) for x in input("").split()]

Maze = []

for i in range(H):
    Maze.append([int(x) for x in input("").split()])

for i in range(0, H):
    print(Maze[i])

l = H + W - 2
ans = 0
moves = [20 * [0]]

for i in range(l):
    if i < W:
        moves[i] = 0
    else:
        moves[i] = 1

