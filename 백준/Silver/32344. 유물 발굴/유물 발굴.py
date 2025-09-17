import sys

r, c = map(int, sys.stdin.readline().split())
n = int(sys.stdin.readline())

gold = {}

for _ in range(n):
    a, v, h = map(int, sys.stdin.readline().split())
    if a not in gold:
        gold[a] = (v, v, h, h)
    else:
        gold[a] = (min(gold[a][0], v), max(gold[a][1], v), min(gold[a][2], h), max(gold[a][3], h))

maximum = 0

for key in gold:
    area = (gold[key][1]-gold[key][0]+1) * (gold[key][3]-gold[key][2]+1)
    if area > maximum:
        ans = key
        maximum = area
    elif area == maximum:
        ans = min(ans, key)

print(ans, maximum)