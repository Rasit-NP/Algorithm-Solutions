import sys

l = int(sys.stdin.readline())
n = int(sys.stdin.readline())
dic = {}
greed = 0
maximum_want = 0
for i in range(1, n+1):
    dic[i] = []

selected = [False] * (l+1)

for people in range(1, n + 1):
    p, k = map(int, sys.stdin.readline().split())
    if k-p > maximum_want:
        greed = people
        maximum_want = k-p
    for i in range(p, k+1):
        if not selected[i]:
            selected[i] = True
            dic[people].append(i)

maximum_get = 0

for key in dic:
    if len(dic[key])>maximum_get:
        maximum_get = len(dic[key])
        pig = key

print(greed)
print(pig)