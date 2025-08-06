import sys
from collections import deque

def bellman_ford(n, start, end, edges):
    dist = [-float('inf')]*n
    dist[start] = earn[start]

    for _ in range(n-1):
        for s, e, c in edges:
            if dist[e] < dist[s] - c + earn[e]:
                dist[e] = dist[s] - c + earn[e]
    
    if dist[end] == -float('inf'):                  # 애초에 도착불가능
        return True, 'gg'

    for s, e, c in edges:
        if dist[e] < dist[s] - c + earn[e]:         # 사이클은 존재함
            dist[e] = dist[s] - c + earn[e]
            cycles.add(e)
    
    if len(cycles) > 0:
        return False, dist[end]
    else:
        return True, dist[end]


n, start, end, m = map(int, sys.stdin.readline().split())
edges = []

for _ in range(m):
    s, e, c = map(int, sys.stdin.readline().split())
    edges.append((s, e, c))

earn = list(map(int, sys.stdin.readline().split()))

cycles = set()
ans = bellman_ford(n, start, end, edges)
queue = deque(cycles)

visited = set()
if queue:
    visited.add(queue[0])

if ans[0] is not False:
    print(ans[1])
else:
    check = 1
    while queue:
        a = queue.popleft()
        if a == end:
            check = 0
            queue.clear()
        for s, e, c in edges:
            if s == a and e not in visited:
                visited.add(e)
                queue.append(e)
    if check == 1:
        print(ans[1])
    elif check == 0:
        print('Gee')