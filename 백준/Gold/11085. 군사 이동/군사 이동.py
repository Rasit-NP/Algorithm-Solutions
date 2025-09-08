import sys, heapq

def input():
    p, w = map(int, sys.stdin.readline().split())
    c, v = map(int, sys.stdin.readline().split())
    edges = [[] for _ in range(p)]

    for _ in range(w):
        s, e, t = map(int, sys.stdin.readline().split())
        edges[s].append((e, t))
        edges[e].append((s, t))

    return p, w, c, v, edges

p, w, c, v, edges = input()

heap = []
visited = [float('inf') for _ in range(p)]
heap.append((-float('inf'), c))
visited[c] = 0

while heap:
    width_total, x = heapq.heappop(heap)
    if x == v:
        ans = -width_total
        heap.clear()
        break
    for nx, width in edges[x]:
        width_new = max(width_total, -width)
        if visited[nx] > width_new:
            visited[nx] = width_new
            heapq.heappush(heap, (width_new, nx))

print(ans)