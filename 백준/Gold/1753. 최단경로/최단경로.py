import sys, heapq

v, e = map(int, sys.stdin.readline().split())
start = int(sys.stdin.readline())
edges = {}      #edges[start] = [(dist1, end1), ...]
visited = [float('inf')] * (v+1)
visited[start] = 0
for i in range(e):
    ini, fin, dist = map(int, sys.stdin.readline().split())
    if ini in edges:
        edges[ini].append((dist, fin))
    else:
        edges[ini] = [(dist, fin)]

heap = [(0, start)]     # (거리, 위치)

while heap:
    now = heapq.heappop(heap)
    nowDistance = now[0]
    nowPosition = now[1]
    if nowPosition in edges:
        for edge in edges[nowPosition]:
            delta_distance = edge[0]
            delta_position = edge[1]
            if visited[delta_position] > nowDistance + delta_distance:
                visited[delta_position] = nowDistance + delta_distance
                heapq.heappush(heap,(visited[delta_position], delta_position))

for i in range(1, v+1):
    if visited[i] == float('inf'):
        print('INF')
    else:
        print(visited[i])