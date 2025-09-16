import heapq

t = int(input())

for tc in range(1, t+1):
    n = int(input())

    board = [list(map(int, list(input().rstrip()))) for _ in range(n)]
    heap = []
    visited = [[float('inf') for _ in range(n)] for _ in range(n)]

    heap.append((0, (0, 0)))
    visited[0][0] = 0

    while heap:
        dist, posi = heapq.heappop(heap)
        x, y = posi
        if x == n-1 and y == n-1:
            ans = dist
            heap.clear()
            break
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] > dist + board[nx][ny]:
                visited[nx][ny] = dist+board[nx][ny]
                heapq.heappush(heap, (visited[nx][ny], (nx, ny)))
    print(f'#{tc}', end=' ')
    print(ans)