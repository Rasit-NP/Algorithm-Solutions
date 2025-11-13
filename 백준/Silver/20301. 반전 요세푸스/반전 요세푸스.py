import sys
from collections import deque

n, k, m = map(int, sys.stdin.readline().split())

queue = deque([i+1 for i in range(n)])
direc = 1
cnt = 0
while queue:
    if direc:
        for _ in range(k-1):
            x = queue.popleft()
            queue.append(x)
        sys.stdout.write(str(queue.popleft())+'\n')
    else:
        for _ in range(k-1):
            x = queue.pop()
            queue.appendleft(x)
        sys.stdout.write(str(queue.pop())+'\n')
    cnt += 1
    if not cnt%m:
        direc = direc^1