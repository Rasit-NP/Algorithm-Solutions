import sys
from collections import deque
def input():
    n, k = map(int, sys.stdin.readline().split())
    times = [0] + list(map(int, sys.stdin.readline().split()))
    edges = {}
    fan_in = [0]*(n+1)
    parents = {}
    for i in range(1, n+1):
        edges[i] = []
        parents[i] = []
    for _ in range(k):
        a, b = map(int, sys.stdin.readline().split())
        edges[a].append(b)
        parents[b].append(a)
        fan_in[b] += 1

    w = int(sys.stdin.readline())
    return n, k, times, edges, fan_in, parents, w

t = int(sys.stdin.readline())
for _ in range(t):
    n, k, times, edges, fan_in, parents, w = input()

    dp = [None] * (n+1)
    queue = deque([])
    for i in range(1, n+1):
        if fan_in[i] == 0:
            dp[i] = times[i]
            queue.append(i)
    
    while queue:
        a = queue.popleft()

        for edge in edges[a]:
            fan_in[edge] -= 1
            if fan_in[edge] == 0:
                queue.append(edge)
                
        maximum = 0
        for parent in parents[a]:
            maximum = max(maximum, dp[parent])
        dp[a] = maximum + times[a]
        if a == w:
            print(dp[w])
            queue.clear()
            break