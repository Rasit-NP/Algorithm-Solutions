import heapq

t = int(input())

for tc in range(1, t+1):
    
    n = int(input())
    board = [list(map(int, input().split())) for _ in range(n)]

    visited = [[float('inf') for _ in range(n)] for _ in range(n)]
    heap = []
    heap.append((0, (0, 0)))
    visited[0][0] = 0

    while heap:
        dist, pos = heapq.heappop(heap)
        x, y = pos
        if x == n-1 and y == n-1:
            ans = dist
            heap.clear()
            break
        if dist > visited[x][y]:
            continue
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n:
                delta = 1
                if board[nx][ny] > board[x][y]:
                    delta += board[nx][ny] - board[x][y]
                if visited[nx][ny] > dist + delta:
                    visited[nx][ny] = dist + delta
                    heapq.heappush(heap, (visited[nx][ny], (nx, ny)))

    print(f'#{tc}', end=' ')
    print(ans)