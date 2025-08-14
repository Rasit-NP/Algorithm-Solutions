import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())

fan_in = [0] * (n+1)
ans = []
queue = deque([])
edges = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    fan_in[b] += 1


while len(ans) < n:
    for i in range(1, n+1):
        if fan_in[i] == 0:
            queue.append(i)
            fan_in[i] = -1

    while queue:
        node = queue.popleft()
        for target in edges[node]:
            fan_in[target] -= 1
        ans.append(node)


print(' '.join(map(str, ans)))