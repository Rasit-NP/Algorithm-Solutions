import sys, math
from collections import deque

def LCA(depth, parents, a, b):
    if depth[a] < depth[b]:
        a, b = b, a
    da, db = 0, 0
    diff = depth[a] - depth[b]
    for k in range(K+1):
        if diff&(1<<k):
            da += parents[a][k][1]
            a = parents[a][k][0]
    if a == b:
        print(da+db)
        return
    for k in range(K, -1, -1):
        if parents[a][k][0] == parents[b][k][0]:
            continue
        da += parents[a][k][1]
        db += parents[b][k][1]
        a = parents[a][k][0]
        b = parents[b][k][0]
    da += parents[a][0][1]
    db += parents[b][0][1]
    print(da+db)

n = int(sys.stdin.readline())
K = int(math.log2(n)) + 1

edges = [[] for _ in range(n+1)]
parents = [[[None, None] for _ in range(K+1)] for _ in range(n+1)]
depth = [None for _ in range(n+1)]

for _ in range(n-1):
    a, b, c = map(int, sys.stdin.readline().split())
    edges[a].append((b, c))
    edges[b].append((a, c))

queue = deque([])
queue.append(1)
parents[1][0] = [0, 0]
depth[1] = 0
while queue:
    x = queue.popleft()
    for nx, dist in edges[x]:
        if parents[nx][0][0] is None:
            parents[nx][0] = [x, dist]
            queue.append(nx)
            depth[nx] = depth[x] + 1

for k in range(1, K+1):
    for x in range(1, n+1):
        if parents[x][k-1][0] is None or parents[parents[x][k-1][0]][k-1][0] is None:
            continue
        parents[x][k][0] = parents[parents[x][k-1][0]][k-1][0]
        parents[x][k][1] = parents[parents[x][k-1][0]][k-1][1] + parents[x][k-1][1]

m = int(sys.stdin.readline())
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    LCA(depth, parents, a, b)