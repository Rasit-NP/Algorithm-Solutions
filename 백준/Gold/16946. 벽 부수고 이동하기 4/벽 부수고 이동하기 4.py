import sys
from collections import deque

def input():
    n, m = map(int, sys.stdin.readline().split())

    board = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]
    visited = [[False]*m for _ in range(n)]

    return n, m, board, visited

n, m, board, visited = input()
ans = [[0]*m for _ in range(n)]
blanks = []

for i in range(n):
    for j in range(m):
        if board[i][j] == 0 and not visited[i][j]:
            queue = deque([])
            queue.append((i, j))
            visited[i][j] = True
            count = 1
            ones = set()
            while queue:
                x, y = queue.popleft()
                for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                    nx, ny = x+dx, y+dy
                    if 0<=nx<n and 0<=ny<m:
                        if board[nx][ny] == 0 and not visited[nx][ny]:
                            count += 1
                            queue.append((nx, ny))
                            visited[nx][ny] = True
                        elif board[nx][ny] != 0:
                            ones.add((nx, ny))
            for x, y in ones:
                board[x][y] += count

for i in range(n):
    for j in range(m):
        sys.stdout.write(str(board[i][j]%10))
    sys.stdout.write('\n')