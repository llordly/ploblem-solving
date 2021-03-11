#3009

xsum = 0
ysum = 0
xset = set()
yset = set()

for i in range(3):
    x, y = map(int, input().split())
    xsum += x
    ysum += y
    xset.add(x)
    yset.add(y)

print(sum(xset) * 2 - xsum, sum(yset) * 2 - ysum)


