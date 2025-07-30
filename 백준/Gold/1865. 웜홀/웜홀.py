import sys

def bellman_ford(n, start, edges):
    dist = [float('inf')]*(n+1)
    dist[start] = 0
    
    for _ in range(n-1):
        for s, e, t in edges:
            if dist[e] > dist[s]+ t:
                dist[e] = dist[s]+ t
    for s, e, t in edges:
        if dist[e] > dist[s] + t:
            return True
    return False

tc = int(sys.stdin.readline())

for _ in range(tc):
    n, m, w = map(int, sys.stdin.readline().split())
    edges = []      # edges = [(start1, end1, time1), (start2, end2, time2), ...]
    ans = []
    for _ in range(m):
        s, e, t = map(int, sys.stdin.readline().split())
        edges.append((s, e, t))
        edges.append((e, s, t))
    for _ in range(w):
        s, e, t = map(int, sys.stdin.readline().split())
        edges.append((s, e, -t))
    for i in range(1, n+1):
        edges.append((0, i, 0))
       
    if bellman_ford(n+1, 0, edges): print('YES')
    else:   print('NO')