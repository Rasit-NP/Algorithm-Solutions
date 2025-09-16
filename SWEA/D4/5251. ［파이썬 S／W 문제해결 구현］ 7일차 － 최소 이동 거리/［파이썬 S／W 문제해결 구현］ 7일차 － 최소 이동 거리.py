import heapq

t = int(input())

for tc in range(1, t+1):
    
    n, e = map(int, input().split())
    edges = [[] for _ in range(n+1)]
    for _ in range(e):
        s, e, w = map(int, input().split())
        edges[s].append((e, w))
    
    heap = []
    visited = [float('inf') for _ in range(n+1)]
    heap.append((0, 0))
    visited[0] = 0

    while heap:
        dist, x = heapq.heappop(heap)
        if x == n:
            ans = dist
            heap.clear()
            break
        if dist > visited[x]:
            continue
        for nx, delta in edges[x]:
            if visited[nx] > dist+delta:
                visited[nx] = dist+delta
                heapq.heappush(heap, (visited[nx], nx))
    
    print(f'#{tc}', end=' ')
    print(ans)