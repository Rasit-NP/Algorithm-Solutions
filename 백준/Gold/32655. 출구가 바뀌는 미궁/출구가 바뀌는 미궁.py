import sys, heapq

n, m, k = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    edges[a].append((b, c))
    edges[b].append((a, c))

x = int(sys.stdin.readline())
exits = list(map(int, sys.stdin.readline().split()))

heap = []
visited = [float('inf') for _ in range(n+1)]
heap.append((0, 1))
visited[1] = 0

while heap:
    t, i = heapq.heappop(heap)
    if t > visited[i]:
        continue
    for ni, dt in edges[i]:
        nt = t + dt
        if nt < visited[ni]:
            visited[ni] = nt
            heapq.heappush(heap, (nt, ni))

minimum = float('inf')

for i in range(x):
    exit = exits[i]
    time = visited[exit]
    cycle = time // (k*x)
    time = time % (k*x)
    if time < k*i:
        minimum = min(minimum, cycle*(k*x) + (k*i))
    elif k*i <= time < k*(i+1):
        minimum = min(minimum, cycle*(k*x) + time)
    else:
        minimum = min(minimum, (cycle+1)*(k*x) + (k*i))


print(minimum)