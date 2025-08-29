import sys, heapq

def input():
    n, m = map(int, sys.stdin.readline().split())

    edges = [[] for _ in range(n+1)]
    for _ in range(m):
        x, y, z = map(int, sys.stdin.readline().split())
        edges[x].append((y, z))
        edges[y].append((x, z))
    
    return n, m, edges

n, m, edges = input()

heap = []
visited = [float('inf')] * (n+1)
heapq.heappush(heap, (0, 1))
visited[1] = 0
passed = [None] * (n+1)

while heap:
    dist, x = heapq.heappop(heap)
    if x == n:
        heap.clear()
        break
    for x_new, delta in edges[x]:
        total = dist+delta
        if visited[x_new] > total:
            visited[x_new] = total
            heapq.heappush(heap, (total, x_new))
            passed[x_new] = x

start = n
used = []
while start is not None:
    used.append((start, passed[start]))
    start = passed[start]

used = used[:-1]
maximum = 0

for ban in used:
    heap = []
    visited = [float('inf')] * (n+1)
    heapq.heappush(heap, (0, 1))
    visited[1] = 0
    
    while heap:
        dist, x = heapq.heappop(heap)
        if x == n:
            heap.clear()
            maximum = max(maximum, dist)
            break
        for x_new, delta in edges[x]:
            if x in ban and x_new in ban:
                continue
            total = dist+delta
            if visited[x_new] > total:
                visited[x_new] = total
                heapq.heappush(heap, (total, x_new))
                passed[x_new] = x

print(maximum)