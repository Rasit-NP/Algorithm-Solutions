import sys, heapq

def input():
    n = int(sys.stdin.readline())
    edges = [[] for _ in range(n+1)]
    for _ in range(n):
        inputs = list(map(int, sys.stdin.readline().split()))
        a = inputs[0]
        i = 1
        while True:
            if inputs[i] == -1:
                break
            else:
                b = inputs[i]
                c = inputs[i+1]
                i += 2
                edges[a].append((b, c))
                edges[b].append((a, c))
    
    return n, edges

n, edges = input()

start = 1
before = None

while True:
    heap = []
    visited = set()
    heapq.heappush(heap,(0, start))
    visited.add(start)
    while heap:
        dist, posi = heapq.heappop(heap)
        for n_posi, delta in edges[posi]:
            if n_posi not in visited:
                visited.add(n_posi)
                heapq.heappush(heap, (dist+delta, n_posi))
    if posi == before:
        ans = dist
        break
    else:
        before = start
        start = posi

print(ans)