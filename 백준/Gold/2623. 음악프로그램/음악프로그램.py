import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
edges = {}
fan_in = [0]*(n+1)
for i in range(1, n+1):
    edges[i] = []

for _ in range(m):
    inputs = list(map(int, sys.stdin.readline().split()))
    for i in range(1, inputs[0]):
        a, b = inputs[i], inputs[i+1]
        edges[a].append(b)
        fan_in[b] += 1

queue = deque([])

for idx in range(1, n+1):
    if fan_in[idx] == 0:
        queue.append(idx)

ans = []
while queue:
    a = queue.popleft()
    ans.append(a)
    for node in edges[a]:
        fan_in[node] -= 1
        if fan_in[node] == 0:
            queue.append(node)

if max(fan_in) == 0:
    sys.stdout.write('\n'.join(map(str, ans)))
else:
    sys.stdout.write('0')