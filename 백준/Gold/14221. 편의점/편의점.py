import sys, heapq

n, m = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    edges[a].append((c, b))
    edges[b].append((c, a))

p, q = map(int, sys.stdin.readline().split())
candidates = sorted(list(map(int, sys.stdin.readline().split())))
gs25 = list(map(int, sys.stdin.readline().split()))


minimum = float('inf')

heap = []
visited = [float('inf')]*(n+1)
for gs in gs25:
    visited[gs] = 0
    heap.append((0, gs))
while heap:
    sum_dist, position = heapq.heappop(heap)
    if position in candidates:
        ans = position
        heap.clear()
        break
    for dist, nextPosition in edges[position]:
        if visited[nextPosition] > sum_dist + dist:
            visited[nextPosition] = sum_dist + dist
            heapq.heappush(heap, (visited[nextPosition], nextPosition))

print(ans)