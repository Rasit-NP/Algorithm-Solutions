import sys
from collections import deque

board = [list(sys.stdin.readline()) for _ in range(8)]
start = (7, 0)
walls = set()
for i in range(8):
    for j in range(8):
        if board[i][j] == '#':
            walls.add((i, j))

queue = deque([])
visited = set()
queue.append((0, 7, 0))
visited.add((0, 7, 0))

ans = 0
while queue:
    t, x, y = queue.popleft()
    if x == 0 and y == 7:
        ans = 1
        break
    if (x-t, y) in walls:
        ans = 0
        continue
    for dx in (-1, 0, 1):
        for dy in (-1, 0, 1):
            nx = x+dx; ny = y+dy
            if not (0<=nx<8 and 0<=ny<8):
                continue
            if (t+1, nx, ny) in visited:
                continue
            if (nx-t, ny) not in walls:
                queue.append((t+1, nx, ny))
                visited.add((t+1, nx, ny))

print(ans)