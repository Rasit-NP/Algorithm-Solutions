import sys, heapq

def dijkstra(dic, heap):
    a = heapq.heappop(heap)
    sumDistance = a[0]
    position = a[1]
    for departure in dic[position]:
        if sumDistance + departure[0] < visited[departure[1]]:
            visited[departure[1]] = sumDistance + departure[0]
            heapq.heappush(heap, (sumDistance + departure[0], departure[1]))
        

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
dic = {}                        ## dic[start] = [(distance1, end1), (distance2, end2), ...]
for i in range(1, n+1):
    dic[i] = []
visited = [float('inf') for _ in range(n+1)]

for _ in range(m):
    ini, fin, distance = map(int, sys.stdin.readline().split())
    dic[ini].append((distance, fin))

start, end = map(int, sys.stdin.readline().split())
heap = []
heapq.heappush(heap, (0, start))            # (distance, position)
visited[start] = 0

while heap:
    if heap[0][1] != end:
        dijkstra(dic, heap)
    else: break

print(visited[end])