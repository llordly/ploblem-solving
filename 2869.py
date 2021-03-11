#2869
import math

a, b, v = map(int, input().split())

day = (v - a) / (a - b)
day = math.ceil(day) + 1

print(day)