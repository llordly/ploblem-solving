#11650

n = int(input())
l = list()
for i in range(n):
    l.append(tuple(map(int, input().split())))

r = sorted(l)

for i in r:
    print(i[0], i[1])