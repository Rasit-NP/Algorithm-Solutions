import sys
from collections import deque

n = int(sys.stdin.readline())

edges = {}
for _ in range(n):
    a, b, c = sys.stdin.readline().split()
    edges[a] = [b, c]

queue = deque([])
visited = set()
queue.append('A')
visited.add('A')

while queue:
    a = queue.popleft()
    sys.stdout.write(a)
    b, c = edges[a]
    if c != '.':
        queue.appendleft(c)
    if b != '.':
        queue.appendleft(b)
sys.stdout.write('\n')


queue = deque([])
visited = set()
queue.append('A')

while queue:
    a = queue.popleft()
    b, c = edges[a]
    if b == '.' or b in visited:
        sys.stdout.write(a)
        visited.add(a)
        if c != '.':
            queue.appendleft(c)
    else:
        queue.appendleft(a)
        queue.appendleft(b)
sys.stdout.write('\n')

queue = deque([])
visited = set()
queue.append('A')

while queue:
    a = queue.popleft()
    b, c = edges[a]
    if (b == '.' or b in visited) and (c == '.' or c in visited):
        sys.stdout.write(a)
        visited.add(a)
    else:
        queue.appendleft(a)
        if c != '.' and c not in visited:
            queue.appendleft(c)
        if b != '.' and b not in visited:
            queue.appendleft(b)
