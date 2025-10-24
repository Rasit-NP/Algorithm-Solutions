import sys, heapq

m, n, k = map(int, sys.stdin.readline().split())
v, w = map(int, sys.stdin.readline().split())

edges = [[] for _ in range(n)]
forbidden = {}

for _ in range(m):
    x, y, c = map(int, sys.stdin.readline().split())
    edges[x].append((y, c))

for _ in range(k):
    x, y, z = map(int, sys.stdin.readline().split())
    if (x, y) not in forbidden:
        forbidden[(x, y)] = [z]
    else:
        forbidden[(x, y)].append(z)

heap = []
visited = [{} for _ in range(n)]
heap.append((0, -1, v))

ans = -1
while heap:
    dist, bx, x = heapq.heappop(heap)
    if x == w:
        heap.clear()
        ans = dist
        break
    cannot = set()
    if (bx, x) in forbidden:
        cannot = cannot | set(forbidden[(bx, x)])
    for nx, new_dist in edges[x]:
        if nx in cannot:
            continue
        ndist = dist+new_dist
        if (x not in visited[nx] or visited[nx][x] > ndist):
            visited[nx][x] = ndist
            heapq.heappush(heap, (ndist, x, nx))

print(ans)