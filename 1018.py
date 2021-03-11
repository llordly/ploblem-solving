#1018

wList = ['WBWBWBWB', 'BWBWBWBW'] * 4
bList = ['BWBWBWBW', 'WBWBWBWB'] * 4

def cut(row, col, chess):
    cuttedChess = list()
    for i in range(row, row + 8):
        temp = chess[i][col:col+8]
        cuttedChess.append(temp)
    return cuttedChess

def count(a, b):
    result = 0
    for i, j in zip(a, b):
        if i != j:
            result += 1
    return result

def retouch(cuttedChess):
    w = 0
    b = 0
    for i, j in zip(wList, cuttedChess):
        w += count(list(i), list(j))
    for i, j in zip(bList, cuttedChess):
        b += count(list(i), list(j))
    return min(w, b)

n, m = map(int, input().split())

chess = list()

for _ in range(n):
    chess.append(input())

ans = 65

for i in range(n - 7):
    for j in range(m - 7):
        temp = retouch(cut(i, j, chess))
        if temp < ans:
            ans = temp

print(ans)

