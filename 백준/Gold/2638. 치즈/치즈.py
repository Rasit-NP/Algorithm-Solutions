import sys
from collections import deque

def input():
    n, m = map(int, sys.stdin.readline().split())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    return n, m, board

n, m, board = input()

time = 0
while True:
    queue = deque([])
    visited = set()
    cheese = {}

    for j in range(m):
        queue.append((0, j))
        queue.append((n-1, j))
        visited.add((0, j))
        visited.add((n-1, j))

    while queue:
        x, y = queue.popleft()
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<m:
                if board[nx][ny] == 0 and (nx, ny) not in visited:
                    queue.append((nx, ny))
                    visited.add((nx, ny))
                elif board[nx][ny] == 1:
                    if (nx, ny) in cheese:
                        cheese[(nx, ny)] += 1
                    else:
                        cheese[(nx, ny)] = 1

    if len(cheese) > 0:
        for (x, y) in cheese:
            if cheese[(x, y)] > 1:
                board[x][y] = 0
        time += 1
    else:
        print(time)
        break