import sys
from collections import deque

def bfs(queue):
    a = queue.popleft()
    x = a[0]
    y = a[1]
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < m and 0 <= ny < n and not visited[ny][nx] and board[ny][nx]:
            queue.append([nx,ny])
            visited[ny][nx] = True
            board[ny][nx] = board[y][x] + 1

n, m = map(int, sys.stdin.readline().split())

board = [0] * n
visited = [[False]*m for _ in range(n)]
visited[0][0] = True

for i in range(n):
    board[i] = list(map(int, list(sys.stdin.readline().rstrip())))

queue = deque([[0, 0]])

while queue:
    bfs(queue)

print(board[n-1][m-1])