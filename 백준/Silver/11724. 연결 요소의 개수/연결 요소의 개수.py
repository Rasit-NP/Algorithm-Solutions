import sys

def dfs(n):
    for edge in edges[n]:
        if edge not in visited:
            visited.add(edge)
            dfs(edge)

n, m = map(int, sys.stdin.readline().split())
edges = {}

for i in range(1, n+1):
    edges[i] = []

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    edges[b].append(a)

visited = set()
count = 0

for i in range(1, n+1):
    if i not in visited:
        count += 1
        dfs(i)

print(count)