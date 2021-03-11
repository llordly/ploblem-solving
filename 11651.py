#11651

n = int(input())
l = list()
for i in range(n):
    l.append(tuple(map(int, input().split())))

r = sorted(l, key = lambda x : (x[1], x[0]))

for i in r:
    print(i[0], i[1])