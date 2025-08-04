import sys, heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

routes = {}
for i in range(1, n+1):
    routes[i] = []

for _ in range(m):
    s, e, c = map(int, sys.stdin.readline().split())
    routes[s].append((c, e))

for i in range(1, n+1):
    heap = [(0, i)]
    visited = [float('inf')]*(n+1)
    visited[i] = 0

    while heap:
        spentTime, nowPosi = heapq.heappop(heap)
        if visited[nowPosi] < spentTime:
            continue
        else:
            for route in routes[nowPosi]:
                dt, newPosi = route
                if visited[newPosi] > spentTime + dt:
                    visited[newPosi] = spentTime + dt
                    heapq.heappush(heap,(visited[newPosi], newPosi))
    
    for j in range(1, n):
        if visited[j] == float('inf'):
            print('0', end=' ')
        else:
            print(visited[j], end=' ')
    if visited[n] == float('inf'):
        print('0')
    else:
        print(visited[n])