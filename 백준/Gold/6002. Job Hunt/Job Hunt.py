import sys

def Bellman_Ford(n, start, edges):
    visited = [-float('inf')]*(n + 1)
    visited[start] = 0
    
    for _ in range(n-1):
        for s, e, d in edges:
            if visited[e] < visited[s] + d:
                visited[e] = visited[s] + d
    
    for s, e, d in edges:
        if visited[e] < visited[s] + d:
            return False
    
    return visited[1:]

dollor, path, city, jet, start = map(int, sys.stdin.readline().split())
edges = []

for _ in range(path):
    ini, fin = map(int, sys.stdin.readline().split())
    edges.append((ini, fin, dollor))

for _ in range(jet):
    ini, fin, cost = map(int, sys.stdin.readline().split())
    edges.append((ini, fin, -cost+dollor))

ans = Bellman_Ford(city, start, edges)

if not ans:
    print(-1)
else:
    print(max(ans)+dollor)