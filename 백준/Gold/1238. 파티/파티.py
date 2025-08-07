import sys

n, m, x = map(int, sys.stdin.readline().split())
times1 = [float('inf')] * (n+1)
times1[x] = 0
times2 = [float('inf')] * (n+1)
times2[x] = 0
edges = []

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((b, a, c))

for _ in range(n-1):
    for a, b, t in edges:
        if times1[b] > times1[a] + t:
            times1[b] = times1[a] + t
        if times2[a] > times2[b] + t:
            times2[a] = times2[b] + t

maximum = 0
for i in range(1, n+1):
    maximum = max(maximum, times1[i]+times2[i])

print(maximum)