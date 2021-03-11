#11729

def hanoi(before, after, n):
    if n == 1:
        print(before, after)
        return

    hanoi(before, 6 - before - after, n - 1)

    print(before, after)

    hanoi(6 - before - after, after, n - 1)
    return

n = int(input())
print(2 ** n - 1)
hanoi(1, 3, n)