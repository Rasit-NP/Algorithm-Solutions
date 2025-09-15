import sys, heapq

def input():
    global n, m, lst, edges, parents
    n, m = map(int, sys.stdin.readline().split())

    lst = [None] + sys.stdin.readline().rstrip().split()

    edges = []
    for _ in range(m):
        u, v, d = map(int, sys.stdin.readline().split())
        edges.append((d, u, v))
    heapq.heapify(edges)

    parents = [i for i in range(n+1)]

    return

def find(x):
    root = x
    while root != parents[root]:
        parents[root] = parents[parents[root]]
        root = parents[root]
    parents[x] = root

    return root

input()
total = 0
roots = set(range(1, n+1))
while edges:
    d, x, y = heapq.heappop(edges)
    if lst[x] == lst[y]:
        continue
    rx, ry = find(x), find(y)
    if rx != ry:
        rx, ry = min(rx, ry), max(rx, ry)
        parents[ry] = rx
        roots.remove(ry)
        total += d
    else:
        continue

if len(roots) == 1:
    print(total)
else:
    print(-1)