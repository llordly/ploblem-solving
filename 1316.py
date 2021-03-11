#1316

n = int(input())
result = 0

def groupcheck(word):
    check = set()
    a = word[0]
    check.add(a)
    for i in range(1, len(word)):
        if word[i] not in check:
            check.add(word[i])
            a = word[i]
            continue
        if word[i] != a and word[i] in check:
            return 0
        a = word[i]
    return 1

for i in range(n):
    result += groupcheck(str(input()))
print(result)
