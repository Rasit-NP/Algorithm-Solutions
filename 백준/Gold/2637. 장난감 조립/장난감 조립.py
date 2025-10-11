import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

goin = [0 for _ in range(n+1)]
goout = [[] for _ in range(n+1)]
cnt = [0 for _ in range(n+1)]
ans = []

for _ in range(m):
    x, y, k = map(int, sys.stdin.readline().split())
    goin[y] += 1
    goout[x].append((y, k))

cnt[n] = 1
queue = deque([])
queue.append(n)

while queue:
    x = queue.popleft()
    if not goout[x]:
        ans.append((x, cnt[x]))
    for nx, k in goout[x]:
        goin[nx] -= 1
        cnt[nx] += k*cnt[x]
        if goin[nx] == 0:
            queue.append(nx)

ans.sort()
for a, b in ans:
    print(a, b)