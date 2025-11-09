import sys, heapq

n = int(sys.stdin.readline())
board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]

heap = []
visited = [[float('inf')]*n for _ in range(n)]
heap.append((0, 0, 0))
visited[0][0] = 0

while heap:
    t, x, y = heapq.heappop(heap)
    if x == n-1 and y == n-1:
        ans = t
        heap.clear()
        break
    if t > visited[x][y]:
        continue
    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        nx, ny = x+dx, y+dy
        if 0<=nx<n and 0<=ny<n:
            if board[nx][ny] == '1' and visited[nx][ny] > t:
                heapq.heappush(heap, (t, nx, ny))
                visited[nx][ny] = t
            elif board[nx][ny] == '0' and visited[nx][ny] > t+1:
                heapq.heappush(heap, (t+1, nx, ny))
                visited[nx][ny] = t+1

print(ans)