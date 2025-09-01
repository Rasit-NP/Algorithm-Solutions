import sys, heapq

def input():
    n, m, k = map(int, sys.stdin.readline().split())
    edges = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, c = map(int, sys.stdin.readline().split())
        edges[v].append((u, c))
    ks = list(map(int, sys.stdin.readline().split()))

    return n, m, k, edges, ks

n, m, k, edges, k_list = input()

heap = []
visited = [float('inf')]*(n+1)
for city in k_list:
    heapq.heappush(heap, (0, city))
    visited[city] = 0

while heap:
    dist_now, pos_now = heapq.heappop(heap)
    if visited[pos_now] < dist_now:
        continue
    for pos_new, dist in edges[pos_now]:
        dist_new = dist_now + dist
        if visited[pos_new] > dist_new:
            visited[pos_new] = dist_new
            heapq.heappush(heap, (dist_new, pos_new))

maximum = 0
idx = None
for i in range(1, n+1):
    if visited[i] > maximum:
        idx = i
        maximum = visited[i]

print(idx)
print(maximum)