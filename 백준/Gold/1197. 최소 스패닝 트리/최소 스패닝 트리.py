import sys, heapq

def find(x):
    root = x
    while root != parents[root]:
        parents[root] = parents[parents[root]]
        root = parents[root]
    parents[x] = root
    return root

v, e = map(int, sys.stdin.readline().split())
edges = []

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((c, a, b))

heapq.heapify(edges)

parents = [i for i in range(v+1)]
total = 0

while edges:
    c, a, b = heapq.heappop(edges)
    ra, rb = find(a), find(b)
    ra, rb = min(ra, rb), max(ra, rb)
    if ra != rb:
        total += c
        parents[rb] = ra

print(total)