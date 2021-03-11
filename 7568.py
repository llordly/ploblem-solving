#7568

def size(x, y, p, q):
    if x < p and y < q:
        return 1
    else:
        return 0

n = int(input())
s = [1] * n
people = list()

for _ in range(n):
     people.append(list(map(int, input().split())))

for i in range(n):
    x = people[i][0]
    y = people[i][1]
    for j in range(n):
        if i == j:
            continue
        p = people[j][0]
        q = people[j][1]
        s[i] += size(x, y, p, q)

s = list(map(str, s))
print(' '.join(s))