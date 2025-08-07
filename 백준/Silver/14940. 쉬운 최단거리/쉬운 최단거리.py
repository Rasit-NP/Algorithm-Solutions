import sys
from collections import deque


n, m = map(int, sys.stdin.readline().split())
board = []
visited = [[-1]*m for _ in range(n)]

for i in range(n):
    inputs = list(map(int, sys.stdin.readline().split()))
    for j in range(m):
        if inputs[j] == 2:
            start = (i, j)
        if inputs[j] == 0:
            visited[i][j] = 0
    board.append(inputs)

visited[start[0]][start[1]] = 0

queue = deque([])
queue.append((start[0],start[1]))

while queue:
    x, y = queue.popleft()
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0<=nx<n and 0<=ny<m and board[nx][ny] != 0 and visited[nx][ny] == -1:
            visited[nx][ny] = visited[x][y] + 1
            queue.append((nx,ny))

for i in range(n):
    print(' '.join(list(map(str, visited[i]))))