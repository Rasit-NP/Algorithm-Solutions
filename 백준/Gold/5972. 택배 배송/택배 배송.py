import sys, heapq

def dijkstra(heap, dic):
    current = heapq.heappop(heap)
    distance = current[0]
    position = current[1]
    
    for path in dic[position]:
        newDistance = distance + path[0]
        newPosition = path[1]
        if newDistance < visited[newPosition]:
            visited[newPosition] = newDistance
            heapq.heappush(heap,(newDistance, newPosition))
        

n, m = map(int, sys.stdin.readline().split())
dic = {}
for i in range(1,n+1):
    dic[i] = []

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    dic[a].append((c, b))           # 출발a, 도착b, 비용c => dic[출발] = [(비용1, 도착1), (비용2, 도착2), ...]
    dic[b].append((c, a))

visited = [float('inf')]*(n+1)
heap = [(0,1)]      # (distance, position)

while heap:
    if heap[0][1] == n:
        print(heap[0][0])
        break
    dijkstra(heap, dic)