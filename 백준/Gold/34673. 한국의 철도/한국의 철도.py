import sys
from collections import deque

n = int(sys.stdin.readline())
edges = [[] for _ in range(n+1)]
data = {}

for _ in range(n-1):
    s, e, d = map(int, sys.stdin.readline().split())
    edges[s].append((e, d))
    edges[e].append((s, d))
populations = list(map(int, sys.stdin.readline().split()))
visited = [float('inf')]*(n+1)
queue = deque([])
visited[1] = 0
queue.append((1, 0))
while queue:
    x, dist = queue.popleft()
    for nx, new_dist in edges[x]:
        if visited[nx] < float('inf'):
            continue
        ndist = dist+new_dist
        if ndist < visited[nx]:
            visited[nx] = ndist
            queue.append((nx, ndist))

for i in range(2, n+1):
    population = populations[i-1]
    dist = visited[i]
    if (dist, population) not in data:
        data[(dist, population)] = 1
    else:
        data[(dist, population)] += 1
ans = n*(n-1)//2
for i in data.values():
    ans -= i*(i-1)//2

print(ans, ans)