#2447

def pattern(n):
    global row, col
    new_col = col
    new_row = row
    if n == 1:
        square[row][col] = '*'
        col += 1
    else:
        for _ in range(3):
            pattern(n // 3)

        row += n // 3
        col = new_col

        pattern(n // 3)
        col += n // 3
        pattern(n // 3)


        col = new_col
        row = new_row + (n // 3) * 2

        for _ in range(3):
            pattern(n // 3)
    row = new_row

n = int(input())
row = 0
col = 0
square = [[' ' for _ in range(n)] for _ in range(n)]

pattern(n)

for i in range(n):
    for j in range(n):
        print(square[i][j], end='')
    print()

