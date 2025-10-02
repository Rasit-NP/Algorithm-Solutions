import sys
from collections import deque

n, m, k = map(int, sys.stdin.readline().split())
board = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]
visited = [[[False for _ in range(k+1)] for _ in range(m)] for _ in range(n)]
queue = deque([])

queue.append((0, 0, 0, 1))      # x, y, 뿌횟, 이동횟
for i in range(k+1):
    visited[0][0][i] = True

ans = -1
while queue:
    x, y, s, t = queue.popleft()
    if x==n-1 and y==m-1:
        ans = t
        queue.clear()
        break
    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        nx = x+dx; ny = y+dy
        if 0<=nx<n and 0<=ny<m:
            if board[nx][ny] == 0 and not visited[nx][ny][s]:
                queue.append((nx, ny, s, t+1))
                visited[nx][ny][s] = True
            elif board[nx][ny] == 1 and s+1<=k and not visited[nx][ny][s+1]:
                queue.append((nx, ny, s+1, t+1))
                visited[nx][ny][s+1] = True
print(ans)