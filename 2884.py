#2884

a, b = map(int, input().split())

if b >= 45:
    b -= 45
else:
    b += 15
    if a == 0:
        a = 23
    else:
        a -= 1
print(a, b)