import sys
from collections import deque

def Bellman_Ford(n, start, edges):
    money = [-float('inf')]*(n+1)
    course = [None]*(n+1)    
    money[start] = 0                        # 위치별 소지금
    course[start] = [str(start)]
    for _ in range(n-1):
        for s, e, c in edges:               # 출발, 도착, 이익
            if money[e] < money[s] + c:
                money[e] = money[s] + c
                course[e] = [' '.join(course[s])]
                course[e].append(str(e))
        

    for s, e, c in edges:
        if money[e] < money[s] + c:
            money[e] = money[s] + c
            cycles.add(e)

    return course[n]

n, m = map(int, sys.stdin.readline().split())
edges = []

for _ in range(m):
    ini, fin, cost = map(int, sys.stdin.readline().split())
    edges.append((ini,fin,cost))


cycles = set()
ans = Bellman_Ford(n, 1, edges)

queue = deque(cycles)
visited = set()
if queue:
    visited.add(queue[0])

check = 0
while queue:
    a = queue.popleft()
    if a == n:
        check = 1
        break
    for s, e, c in edges:
        if s == a and e not in visited:
            visited.add(e)
            queue.append(e)


if ans and check == 0:
    print(' '.join(ans))
else:
    print(-1)