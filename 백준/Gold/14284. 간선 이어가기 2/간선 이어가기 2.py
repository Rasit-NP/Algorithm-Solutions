import sys, heapq

n, m = map(int, sys.stdin.readline().split())
edges = {}      # (ini, fin, distance)
heap = []

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    if a in edges:
        edges[a].append((c, b))     # edges[start] = [(distance, edge), ...]
    else:
        edges[a] = [(c, b)]
    if b in edges:
        edges[b].append((c, a))
    else:
        edges[b] = [(c, a)]
    
start, end = map(int, sys.stdin.readline().split())
visited = [float('inf')]*(n+1)
heapq.heappush(heap,(0, start))     # heap = [(distance, position)]

while heap:
    nearest = heapq.heappop(heap)
    nowDistance = nearest[0]
    nowPosition = nearest[1]
    if nowPosition == end:
        print(nowDistance)
        heap.clear()
        break
    for edge in edges[nowPosition]:
        newPosition = edge[1]
        newDistance = nowDistance + edge[0]
        if visited[newPosition] > newDistance:
            visited[newPosition] = newDistance
            heapq.heappush(heap, (newDistance, newPosition))