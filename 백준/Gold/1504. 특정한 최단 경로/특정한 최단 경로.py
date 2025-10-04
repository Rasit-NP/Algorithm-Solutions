import sys, heapq

n, e = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(n+1)]
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    edges[a].append((b, c))
    edges[b].append((a, c))
v1, v2 = map(int, sys.stdin.readline().split())

dp = [[float('inf') for _ in range(4)] for _ in range(4)]
for i in range(4):
    dp[i][i] = 0
groups = ((0, 1), (0, 2), (1, 2), (1, 3), (2, 3))
pos = (1, v1, v2, n)

for idx1, idx2 in groups:
    start = pos[idx1]; end = pos[idx2]
    heap = []
    visited = [float('inf') for _ in range(n+1)]
    heap.append((0, start))
    visited[start] = 0
    while heap:
        d, x = heapq.heappop(heap)
        if x == end:
            dp[idx1][idx2] = d
            heap.clear()
            break
        for nx, dd in edges[x]:
            nd = d + dd
            if visited[nx] > nd:
                visited[nx] = nd
                heapq.heappush(heap, (nd, nx))

route1 = dp[0][1] + dp[1][2] + dp[2][3]
route2 = dp[0][2] + dp[1][2] + dp[1][3]

ans = min(route1, route2)
if ans == float('inf'):
    print(-1)
else:
    print(ans)