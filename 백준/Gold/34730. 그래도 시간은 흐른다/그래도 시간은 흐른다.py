import sys, heapq

n, m, k, s, t = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(n+1)]
for _ in range(m):
    u, v, c, phi = map(int, sys.stdin.readline().split())
    edges[u].append((v, c, phi))

heap = []
visited = [float('inf') for _ in range(n+1)]
heap.append((0, s))
visited[s] = 0
ans = -1
while heap:
    time, x = heapq.heappop(heap)
    if visited[x]<time:
        continue
    if x == t:
        ans = time
        heap.clear()
        break
    for nx, dt, phi in edges[x]:
        if time % phi:
            continue
        nt = time + dt
        if visited[nx] > nt:
            visited[nx] = nt
            heapq.heappush(heap, (nt, nx))
print(ans)