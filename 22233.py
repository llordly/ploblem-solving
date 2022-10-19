#22233 가희와 키워드
import sys


n, m = map(int, sys.stdin.readline().split())
ans = n
dic = dict()

for i in range(n):
    keyword = sys.stdin.readline().rstrip()
    dic[keyword] = 1

for i in range(m):
    keywords = sys.stdin.readline().rstrip().split(',')
    for x in keywords:
        if dic.get(x) != None:
            if dic[x] == 1:
                dic[x] = 0
                ans -= 1
    print(ans)
