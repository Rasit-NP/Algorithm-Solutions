import sys
from collections import deque

n = int(sys.stdin.readline())
board = []
for _ in range(n):
    board.append(list(map(int, list(sys.stdin.readline().rstrip()))))

visited = set()
houses = []

for i in range(n):
    for j in range(n):
        if (i,j) not in visited and board[i][j] == 1:
            queue = deque([(i,j)])
            visited.add((i,j))
            count = 1
            while queue:
                x, y = queue.popleft()
                dx = [1, -1, 0, 0]
                dy = [0, 0, 1, -1]

                for k in range(4):
                    nx = x+dx[k]
                    ny = y+dy[k]
                    if 0<=nx<n and 0<=ny<n and board[nx][ny] == 1 and (nx,ny) not in visited:
                        queue.append((nx,ny))
                        visited.add((nx,ny))
                        count += 1
            houses.append(count)
houses.sort()

a = len(houses)

print(a)
for i in range(a):
    print(houses[i])