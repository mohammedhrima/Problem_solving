if __name__ == "__main__":
    height, width = map(int, input().split())
    grid = []

    for x in range(height):
        row = input()
        grid.append(row)

    for j in range(height):
        for i in range(width):
            if grid[j][i].isdigit():
                power = int(grid[j][i])
                grid[j] = grid[j][:i] + "." + grid[j][i+1:]
                for y in range(height):
                    for x in range(width):
                        if abs(i - x) + abs(j - y) <= power and grid[y][x] == '#':
                            grid[y] = grid[y][:x] + "." + grid[y][x+1:]

    for row in grid:
        print(row)
