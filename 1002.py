#1002
n = int(input())
for _ in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    if x1 == x2 and y1 == y2:
        if r1 == r2:
            print(-1)
        else:
            print(0)
    else:
        r = r1 + r2
        d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
        largeR = r1 if r1 > r2 else r2
        smallR = r1 if r1 < r2 else r2
        if largeR - d > smallR:
            print(0)
        elif largeR - d == smallR:
            print(1)
        else:
            if r == d:
                print(1)
            elif r < d:
                print(0)
            else:
                print(2)