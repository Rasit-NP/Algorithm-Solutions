import sys
from collections import deque

n = int(sys.stdin.readline())

nodes = [None] * (n+1)
nodes[1] = 0
edges = [[] for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    edges[b].append(a)

queue = deque([])
queue.append(1)
visited = set()
visited.add(1)

while queue:
    a = queue.popleft()
    for node in edges[a]:
        if node not in visited:
            nodes[node] = a
            queue.append(node)
            visited.add(node)

print('\n'.join(map(str, nodes[2:])))