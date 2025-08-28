import sys, heapq

def input():
    n, m, k = map(int, sys.stdin.readline().split())
    edges = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))

    return n, m, k, edges

n, m, k, edges = input()

heap = []
heapq.heappush(heap, (0, 1, 0))         # 거리, 위치, 포장 횟수
visited = [[float('inf')]*(k+1) for _ in range(n+1)]
visited[1][0] = 0

while heap:
    dist, x, t = heapq.heappop(heap)
    if visited[x][t] < dist:
        continue

    if x == n:
        ans = dist
        heap.clear()
        break
    for next, delta in edges[x]:
        if visited[next][t] > dist + delta:
            check = True
            new = dist+delta
            for i in range(t):
                if visited[next][i] < new:
                    check = False
                    break
            if check:
                visited[next][t] = dist + delta
                heapq.heappush(heap, (visited[next][t], next, t))
        if t < k and visited[next][t+1] > dist:
            check = True
            for i in range(t+1):
                if visited[next][i] < dist:
                    check = False
                    break
            if check:
                visited[next][t+1] = dist
                heapq.heappush(heap, (visited[next][t+1], next, t+1))

print(ans)