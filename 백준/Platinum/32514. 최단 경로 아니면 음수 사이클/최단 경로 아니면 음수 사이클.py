import sys
from collections import deque

def input():
    n, m, s = map(int, sys.stdin.readline().split())
    edges = []
    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().split())
        edges.append((a, b, c))
    return n, m, s, edges



n, m, s, edges = input()

visited = [float('inf')] * n
visited[s] = 0
prev = [None] * n

cycle = False
updated = True

for _ in range(n-1):
    updated = False
    for s, e, d in edges:
        if visited[e] > visited[s] + d:
            visited[e] = visited[s] + d
            prev[e] = s
            updated = True
    if not updated:
        break
for s, e, d in edges:
    if visited[e] > visited[s] + d:
        visited[e] = visited[s] + d
        detected = s
        cycle = True
        break

if not cycle:
    print('PATH')
    print(' '.join(map(str, visited)))
else:
    print('CYCLE')
    x = detected
    for _ in range(n):
        x = prev[x]
    ans = deque([])
    dup = set()
    while True:
        if x not in dup:
            ans.appendleft(x)
            dup.add(x)
            x = prev[x]
        else:
            break
    print(len(ans))
    ans.appendleft(x)
    print(' '.join(map(str, ans)))