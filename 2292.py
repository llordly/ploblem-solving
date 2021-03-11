#2292

def sum_n(n):
    return n * (n + 1) // 2

n = int(input())
if n == 1:
    print(1)
else:
    result = (n - 2) // 6

    for i in range(1, 18258):
        if sum_n(i) > result:
            print(i + 1)
            break