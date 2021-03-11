#2588

a = input()
b = input()
c = 0
result = 0

for i in reversed(range(3)):
    c = int(a) * int(b[i])
    result += c * (10 ** (2-i))
    print(c)

print(result)