import sys, heapq

def find(x):
    root = x
    while root != parents[root]:
        parents[root] = parents[parents[root]]
        root = parents[root]
    parents[x] = root
    return root

n, m = map(int, sys.stdin.readline().split())

edges = []
parents = [i for i in range(n+1)]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((c, a, b))
heapq.heapify(edges)

count = 0
ans = 0
while count < n-2:
    dist, x, y = heapq.heappop(edges)
    rx, ry = find(x), find(y)
    if rx == ry:
        continue
    else:
        parents[ry] = rx
        count += 1
        ans += dist
print(ans)