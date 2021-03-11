#1436

n = int(input())
count = 0
end = 0

while count < n:
    if '666' in str(end):
        count += 1
        end += 1
    else:
        end += 1
print(end - 1)