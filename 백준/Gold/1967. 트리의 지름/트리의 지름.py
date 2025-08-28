import sys, heapq

def input():
    n = int(sys.stdin.readline())

    edges = [[] for _ in range(n+1)]
    for _ in range(n-1):
        a, b, c = map(int, sys.stdin.readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))
    
    return n, edges

n, edges = input()

a = 1
b = None
while True:
    heap = []
    visited = set()
    heapq.heappush(heap, (0, a))
    visited.add(a)
    while heap:
        dist, x = heapq.heappop(heap)
        for next, delta in edges[x]:
            if next not in visited:
                visited.add(next)
                heapq.heappush(heap, (dist+delta, next))
    if x == b: break
    b = a
    a = x

print(dist)