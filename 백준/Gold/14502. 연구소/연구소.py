import sys
from collections import deque
from itertools import combinations

def input():
    n, m = map(int, sys.stdin.readline().split())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    germs = []
    walls = set()
    blanks = []
    for i in range(n):
        for j in range(m):
            if board[i][j] == 2:
                germs.append((i, j))
            elif board[i][j] == 1:
                walls.add((i, j))
            else:
                blanks.append((i, j))

    return n, m, board, germs, walls, blanks

def conta(germs):
    queue = deque([])
    visited = set()
    for germ in germs:
        queue.append(germ)
        visited.add(germ)
    while queue:
        x, y = queue.popleft()
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<m and (nx, ny) not in walls and (nx, ny) not in visited:
                queue.append((nx, ny))
                visited.add((nx, ny))
    return n*m - (len(visited)+len(walls))

def simul():
    global maximum
    for com in combinations(blanks, 3):
        for position in com:
            walls.add(position)
        maximum = max(maximum, conta(germs))
        for position in com:
            walls.remove(position)

            
            
    return maximum

n, m, board, germs, walls, blanks = input()
maximum = 0

ans = simul()

print(ans)