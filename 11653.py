#11653

n = int(input())
i = 2
while(i <= n):
    if i > n ** 0.5:
        print(n)
        break
    if n % i == 0:
        print(i)
        n //= i
    else:
        i += 1