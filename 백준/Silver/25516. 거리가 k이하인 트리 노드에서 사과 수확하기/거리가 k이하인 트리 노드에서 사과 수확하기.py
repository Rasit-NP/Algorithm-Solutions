import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(n)]
for _ in range(n-1):
    p, c = map(int, sys.stdin.readline().split())
    edges[p].append(c)

apples = list(map(int, sys.stdin.readline().split()))

queue = deque([])
queue.append((0, 0))

ans = 0
while queue:
    dist, position = queue.popleft()
    if dist > k:
        queue.clear()
        break
    
    ans += apples[position]
    for edge in edges[position]:
        queue.append((dist+1, edge))

print(ans)