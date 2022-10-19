# 5430
from collections import deque

t = int(input())
command = None

for i in range(t):
    d = deque()
    ans = "["
    error = False
    reverse = False
    command = input()
    n = input()
    arr = input()
    arr = arr[1:-1]
    arr = arr.split(",")
    if arr[0] != "":
        for x in arr:
            d.append(x)

    for x in command:
        if x == "R":
            reverse = not reverse
        else:
            if len(d) == 0:
                print("error")
                error = True
                break
            if reverse:
                d.pop()
            else:
                d.popleft()
    if error:
        continue
    else:
        if reverse:
            while len(d) > 0:
                if len(d) == 1:
                    ans += d.pop()
                else:
                    ans += d.pop() + ","
        else:
            while len(d) > 0:
                if len(d) == 1:
                    ans += d.popleft()
                else:
                    ans += d.popleft() + ","
        ans = ans + "]"
    print(ans)