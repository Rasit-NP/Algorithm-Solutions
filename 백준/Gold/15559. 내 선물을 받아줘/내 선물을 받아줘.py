import sys

n, m = map(int, sys.stdin.readline().split())

board = [list(input().rstrip()) for _ in range(n)]
visited = set()
direction = {'N': (-1, 0), 'W': (0, -1), 'E': (0, 1), 'S': (1, 0)}
count = 0

for i in range(n):
    for j in range(m):
        x, y = i, j
        sets = set()
        while (x, y) not in visited:
            visited.add((x, y))
            sets.add((x, y))
            dx, dy = direction[board[x][y]]
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<m:
                if (nx, ny) not in visited:
                    x, y = nx, ny
                elif (nx, ny) in sets:
                    count += 1

print(count)