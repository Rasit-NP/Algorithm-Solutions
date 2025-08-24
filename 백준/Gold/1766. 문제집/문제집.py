import sys,heapq

def input():
    n, m = map(int, sys.stdin.readline().split())

    fan_in = [0] * (n+1)
    edges = {}
    for i in range(1, n+1):
        edges[i] = []
    
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        edges[a].append(b)
        fan_in[b] += 1
    
    return n, m, edges, fan_in

n, m, edges, fan_in = input()

heap = []

for i in range(1, n+1):
    if fan_in[i] == 0:
        heapq.heappush(heap, i)
ans = []
while heap:
    a = heapq.heappop(heap)
    ans.append(a)
    for b in sorted(edges[a]):
        fan_in[b] -= 1
        if fan_in[b] == 0:
            heapq.heappush(heap, b)

print(' '.join(map(str, ans)))