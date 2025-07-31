import sys, heapq

n, m, start, end = map(int, sys.stdin.readline().split())
edges = {}
visited = [float('inf')]*(n+1)
visited[start] = 0
heap = [(0, start)]         #(누적비용, 위치)

for _ in range(m):
    ini, fin, cost = map(int, sys.stdin.readline().split())
    if ini in edges:
        edges[ini].append((cost, fin))      #(거리비용, 도착점)
    else:
        edges[ini] = [(cost, fin)]
    if fin in edges:
        edges[fin].append((cost, ini))
    else:
        edges[fin] = [(cost, ini)]

while heap:
    currentCost, currentPosition = heapq.heappop(heap)
    if currentPosition == end:
        print(currentCost)
        break
    for edge in edges[currentPosition]:
        nextCost = currentCost + edge[0]
        nextPosition = edge[1]
        if visited[nextPosition] > nextCost:
            visited[nextPosition] = nextCost
            heapq.heappush(heap,(nextCost, nextPosition))