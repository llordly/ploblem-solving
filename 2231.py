#2231

def constructor(n):
    result = n
    digit = str(n)
    for i in range(len(digit)):
        result += int(digit[i])
    return result


n = int(input())
min = 1000000
for i in range(n + 1):
    temp = constructor(i)
    if temp == n:
        min = i
        break

if min == 1000000:
    print(0)
else:
    print(min)