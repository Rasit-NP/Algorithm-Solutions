import sys, heapq

n, m = map(int, sys.stdin.readline().split())

sight = list(map(int, sys.stdin.readline().split()))
routes = {}
heap = [(0, 0)]
visited = [float('inf')]*n
visited[0] = 0
for i in range(n):
    routes[i] = []

for _ in range(m):
    s, e, t = map(int, sys.stdin.readline().split())
    if sight[s] + sight[e] == 0 or (s == n-1 and sight[e] == 0) or (e == n-1 and sight[s] == 0):
        routes[s].append((t, e))
        routes[e].append((t, s))

while heap:
    total, nowPosi = heapq.heappop(heap)
    if nowPosi == n-1:
        print(total)
        break

    if total > visited[nowPosi]:
        continue

    for route in routes[nowPosi]:
        dt, newPosi = route

        if total + dt < visited[newPosi]:
            visited[newPosi] = total + dt
            heapq.heappush(heap, (visited[newPosi], newPosi))

else:
    print(-1)