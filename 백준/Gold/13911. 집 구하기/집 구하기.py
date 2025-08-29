import sys, heapq

def input():
    v, e = map(int, sys.stdin.readline().split())
    edges = [[] for _ in range(v+1)]
    for _ in range(e):
        a, b, c = map(int, sys.stdin.readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))
    
    m, x = map(int, sys.stdin.readline().split())
    mac = list(map(int, sys.stdin.readline().split()))
    s, y = map(int, sys.stdin.readline().split())
    star = list(map(int, sys.stdin.readline().split()))

    return v, e, edges, m, x, mac, s, y, star

v, e, edges, m, x, macs, s, y, stars = input()

## 맥세권
heap = []
visited = [float('inf')]*(v+1)

for mac in macs:
    heapq.heappush(heap, (0, mac))
    visited[mac] = 0

ans_mac = {}

while heap:
    dist_now, pos_now = heapq.heappop(heap)
    for pos_new, dist in edges[pos_now]:
        dist_new = dist_now+dist
        if visited[pos_new] > dist_new and dist_new <= x:
            visited[pos_new] = dist_new
            heapq.heappush(heap, (dist_new, pos_new))
            ans_mac[pos_new] = dist_new

## 스세권
heap = []
visited = [float('inf')]*(v+1)

for star in stars:
    heapq.heappush(heap, (0, star))
    visited[star] = 0

ans_star = {}

while heap:
    dist_now, pos_now = heapq.heappop(heap)
    for pos_new, dist in edges[pos_now]:
        dist_new = dist_now+dist
        if visited[pos_new] > dist_new and dist_new <= y:
            visited[pos_new] = dist_new
            heapq.heappush(heap, (dist_new, pos_new))
            ans_star[pos_new] = dist_new

lst = set(ans_mac.keys()) & set(ans_star.keys())

if lst:
    minimum = float('inf')
    for house in lst:
        minimum = min(minimum, ans_mac[house]+ans_star[house])
    print(minimum)
else:
    print(-1)