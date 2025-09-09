import sys
from collections import deque

n, m, r = map(int, sys.stdin.readline().split())
nums = [0] + list(map(int, sys.stdin.readline().split()))
edges = [[] for _ in range(n+1)]

for _ in range(r):
    a, b, l = map(int, sys.stdin.readline().split())
    edges[a].append((l, b))
    edges[b].append((l, a))

queue = deque([])
maximum = 0
for i in range(1, n+1):
    queue.append((0, i))
    visited = set([i])
    while queue:
        dist_now, x = queue.popleft()
        for dist, nx in edges[x]:
            dist_new = dist + dist_now
            if dist_new <= m:
                queue.append((dist_new, nx))
                visited.add(nx)
    total = 0
    for position in visited:
        total += nums[position]
    maximum = max(maximum, total)

print(maximum)