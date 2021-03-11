#4153

x, y, z = map(int, input().split())

while x and y and z != 0:
    check = list()
    check.append(x)
    check.append(y)
    check.append(z)
    check.sort()
    if check[0] ** 2 + check[1] ** 2 == check[2] ** 2:
        print('right')
    else:
        print('wrong')
    x, y, z = map(int, input().split())