#2798

from itertools import combinations

n , m = map(int, input().split())
card = list(map(int, input().split()))

newCard = list(combinations(card, 3))

max = 0
for x in newCard:
    temp = sum(x)
    if m >= temp > max:
        max = temp

print(max)