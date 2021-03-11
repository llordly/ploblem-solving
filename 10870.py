#10870

n = int(input())

fibonacci = [0 for _ in range(21)]
fibonacci[1] = 1

if n >= 2:
    for i in range(2, n + 1):
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]
print(fibonacci[n])