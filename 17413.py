#17413 단어 뒤집기 2
#문자열, 정규표현식

import re

r = re.compile('<[a-z ]+>|[a-z0-9 ]+')
regs = r.findall(input())


ans = ''
for x in regs:
    if x[0] == '<':
        ans += x
    else:
        temp = x.split(' ')
        rev = []
        for y in temp:
            y = y[::-1]
            rev.append(y)
        rev = " ".join(rev)
        ans += rev

print(ans)