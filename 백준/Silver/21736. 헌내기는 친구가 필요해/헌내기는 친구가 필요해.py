import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
board = []
for i in range(n):
    inputs = list(sys.stdin.readline().rstrip())
    board.append(inputs)
    for j in range(m):
        if inputs[j] == 'I':
            start = (i, j)


queue = deque([])
visited = set()

queue.append(start)
visited.add(start)

count = 0
while queue:
    x, y = queue.popleft()
    if board[x][y] == 'P':
        count += 1
    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] != 'X' and (nx, ny) not in visited:
            queue.append((nx, ny))
            visited.add((nx, ny))

if count:
    print(count)
else:
    print('TT')