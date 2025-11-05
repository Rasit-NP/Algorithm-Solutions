import sys

n, m, q = map(int, sys.stdin.readline().split())
edges = [{} for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    if b in edges[a]:
        edges[a][b] = min(edges[a][b], c)
    else:
        edges[a][b] = c
    if a in edges[b]:
        edges[b][a] = min(edges[b][a], c)
    else:
        edges[b][a] = c

for _ in range(q):
    minimum = float('inf')
    s, e = map(int, sys.stdin.readline().split())
    if e in edges[s]:
        print(edges[s][e])
    else:
        print(-1)