import sys, heapq

def dijkstra(dic, heap):
    a = heapq.heappop(heap)
    distance = a[0]
    position = a[1]
    if position == d:
        print(distance)
        heap.clear()
    elif position < d:
        if position in dic:
            for i in dic[position]:
                heapq.heappush(heap, (distance+i[1], i[0]))
                if i[0] not in visited and i[0] <= d:
                    visited[i[0]] = distance+i[1]
                else:
                    visited[i[0]] = min(visited[i[0]], distance+i[1])
        newDistance = distance + 1
        newPosition = position + 1
        heapq.heappush(heap, (newDistance, newPosition))

n, d = map(int, sys.stdin.readline().split())
dic = {}
heap = [(0, 0)]     ##(거리, 위치)
visited = {}

for _ in range(n):
    start, end, distance = map(int, sys.stdin.readline().split())
    if end <= d:
        if start not in dic:
            dic[start] = [(end, distance)]
        else:
            dic[start].append((end, distance))

while heap:
    dijkstra(dic, heap)