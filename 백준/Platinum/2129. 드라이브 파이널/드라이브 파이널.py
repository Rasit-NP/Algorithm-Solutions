import sys
from collections import deque

def bellman_ford(n, start, edges):
    visited = [[float('inf')]*n, [float('inf')]*n]          # 피로도, 거리
    visited[0][start] = 0
    visited[1][start] = 0
    for _ in range(n-1):
        for u in range(n):
            for v, tired, dist in edges[u]:
                newtired = visited[0][u] + tired
                newdist = visited[1][u] + dist
                if visited[0][v] > newtired:
                    visited[0][v] = newtired
                    visited[1][v] = newdist
                elif visited[0][v] == newtired:
                    visited[1][v] = min(visited[1][v], newdist)

    for u in range(n):
        for v, tired, dist in edges[u]:
            newtired = visited[0][u] + tired
            newdist = visited[1][u] + dist
            if visited[0][v] > newtired:
                visited[0][v] = newtired
                cycles.add(v)

    return visited

n, m, s, t = map(int, sys.stdin.readline().split())

edges = {}                              # edges[출발] = [(도착1, 피로도1, 거리1), (...)]
for i in range(n):
    edges[i] = [(s, float('inf'), float('inf'))]
cycles = set()
for _ in range(m):
    u, v, a, c, b = map(int, sys.stdin.readline().split())
    if u not in edges:
        edges[u] = [(v, a, c)]
    else:
        if edges[u][0][1] > a:
            edges[u] = [(v, a, c)]
        elif edges[u][0][1] == a:
            edges[u].append((v, a, c))
    
    if v not in edges:
        edges[v] = [(u, b, c)]
    else:
        if edges[v][0][1] > b:
            edges[v] = [(u, b, c)]
        elif edges[v][0][1] == b:
            edges[v].append((u, b, c))

ans = bellman_ford(n,s,edges)
queue = deque(cycles)
test = cycles

if ans[0][t] == float('inf'):
    print('VOID')
else:
    if len(cycles) == 0:
        print(ans[0][t], ans[1][t])
    else:
        while queue:
            pos = queue.popleft()
            if pos in edges:
                for v, tired, dist in edges[pos]:
                    if v not in test:
                        queue.append(v)
                        test.add(v)
        if t not in test:
            print(ans[0][t], ans[1][t])
        else:
            print('UNBOUND')