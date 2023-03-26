"""
. represents empty square
# represents square with wall
1,2,...9 represnets square with a bomb
it exploids depends on the power of the bomb
"""
# take number of rows and columns
Row, Column = [int(x) for x in input("").split()]

# feed board
board = []
for x in range(Row):
    board.append(input(""))

# iterate over board
for i in range(Row):
    for j in range(Column):
        if board[i][j] in "123456789":
            # there is a bomb
            power = int(board[i][j])
            
            for r in range(Row):
                for c in range(Column):
                    if abs(r - i) + abs(c - j) <= power:
                        board[r] = board[r][:c] + "." + board[r][c+1:]

print("\n")
for string in board:
    print(string)