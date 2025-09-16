import sys, heapq

n = int(sys.stdin.readline())
blocks = [(0, 0, 0)]

for i in range(n):
    a, h, w = map(int, sys.stdin.readline().split())
    blocks.append((a, h, w))

edges = [[] for _ in range(n+1)]

for i in range(n+1):
    a1, h1, w1 = blocks[i]
    for j in range(i+1, n+1):
        a2, h2, w2 = blocks[j]
        if a1 < a2 and w1 < w2:
            edges[i].append((j, h2))
        elif a1 > a2 and w1 > w2:
            edges[j].append((i, h1))

heap = []
visited = [0 for _ in range(n+1)]
parents = [None for _ in range(n+1)]

heap.append((0, 0))
visited[0] = 0
while heap:
    h, x = heapq.heappop(heap)
    if h < visited[x]:
        continue
    for nx, dh in edges[x]:
        if visited[nx] < h+dh:
            visited[nx] = h+dh
            parents[nx] = x
            heapq.heappush(heap, (h+dh, nx))

ans = []
while x > 0:
    ans.append(x)
    x = parents[x]

ans.reverse()

print(len(ans))
for x in ans:
    print(x)