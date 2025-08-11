import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

queue = deque([])
queue.append((0, n))
visited = [float('inf')] * 100001
visited[n] = 0
count = 0

while queue:
    time, position = queue.popleft()
    nxs = [position+1, position-1, position*2]
    if position == k:
        if visited[k] == float('inf'):
            visited[k] = time
            count += 1
            continue
        elif time == visited[k]:
            count += 1
            continue
    if time > visited[k]:
        queue.clear()
        break
    for nx in nxs:
        if 0<=nx<=100000 and time+1 <= visited[nx]:
            visited[nx] = time+1
            queue.append((time+1, nx))

print(visited[k])
print(count)