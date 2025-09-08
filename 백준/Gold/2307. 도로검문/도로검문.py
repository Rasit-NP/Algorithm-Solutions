import sys, heapq

def input():
    n, m = map(int, sys.stdin.readline().split())
    edges = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b, t = map(int, sys.stdin.readline().split())
        edges[a].append((b, t))
        edges[b].append((a, t))
    
    return n, m, edges

n, m, edges = input()

heap = []
visited = [[float('inf'), None] for _ in range(n+1)]
heapq.heappush(heap, (0, 1))
visited[1][0] = 1

while heap:
    total, x = heapq.heappop(heap)
    if x == n:
        before = total
        heap.clear()
        break
    for nx, dist in edges[x]:
        dist_new = total + dist
        if visited[nx][0] > dist_new:
            visited[nx][0] = dist_new
            visited[nx][1] = x
            heapq.heappush(heap, (dist_new, nx))

trace = []
y = n
while y:
    trace.append(y)
    y = visited[y][1]

trace.reverse()

ans = 0
for i in range(len(trace)-1):
    ban1, ban2 = trace[i], trace[i+1]
    heap = []
    visited = [float('inf') for _ in range(n+1)]
    heapq.heappush(heap, (0, 1))
    visited[1] = 0
    while heap:
        total, x = heapq.heappop(heap)
        if x == n:
            ans = max(ans, total)
            heap.clear()
            break
        for nx, dist in edges[x]:
            if (x == ban1 and nx == ban2) or (x == ban2 and nx == ban1):
                continue
            dist_new = total + dist
            if visited[nx] > dist_new:
                visited[nx] = dist_new
                heapq.heappush(heap, (dist_new, nx))
    if visited[n] == float('inf'):
        ans = 0
        break

if ans:
    print(ans - before)
else:
    print(-1)