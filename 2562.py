#2562

a = list()
for i in range(9):
    a.append(int(input()))

m = max(a)
print(max(a))
print(a.index(m)+1)