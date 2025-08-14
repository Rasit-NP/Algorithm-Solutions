import sys
from collections import deque

n = int(sys.stdin.readline())
moms = list(map(int, sys.stdin.readline().split()))
target = int(sys.stdin.readline())
edges = [[] for _ in range(n+1)]
for i in range(n):
    if moms[i] == -1:
        root = i
    else:
        edges[moms[i]].append(i)

queue = deque([])
queue.append(root)

if target == root:
    print(0)
else:
    count = 0
    while queue:
        node = queue.popleft()
        if edges[node] == [target] or edges[node] == []:
            count += 1
        else:
            for edge in edges[node]:
                if edge == target:
                    continue
                else:
                    queue.append(edge)
    print(count)