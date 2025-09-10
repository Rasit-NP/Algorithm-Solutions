import sys
from collections import deque

n = int(sys.stdin.readline())

edges = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    edges[b].append(a)

a, b, x = map(int, sys.stdin.readline().split())

queue = deque([])
visited = set()
visited.add(x)
counts = [0 for _ in range(len(edges[x]))]

for i in range(len(edges[x])):
    queue.append((i, edges[x][i]))
    visited.add(edges[x][i])
    counts[i] += 1


while queue:
    direction, position = queue.popleft()
    if position == a or position == b:
        counts[direction] = None
    for nx in edges[position]:
        if nx not in visited and counts[direction] is not None:
            visited.add(nx)
            queue.append((direction, nx))
            counts[direction] += 1

total = 0
for i in range(len(counts)):
    if counts[i]:
        total += counts[i]

print(total + 1)