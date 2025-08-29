import sys

def input():
    n, m = map(int, sys.stdin.readline().split())
    board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
    cleared = [[False]*m for _ in range(n)]

    return n, m, board, cleared

n, m, board, cleared = input()
directions = {'U':(-1, 0), 'D':(1, 0), 'L':(0, -1), 'R':(0, 1)}
count = 0

for i in range(n):
    for j in range(m):
        if cleared[i][j]:
            continue
        else:
            x, y = i, j
            visited = set()
            while True:
                visited.add((x, y))
                cleared[x][y] = True
                dx, dy = directions[board[x][y]]
                nx, ny = x+dx, y+dy
                if cleared[nx][ny]:
                    if (nx ,ny) in visited:
                        count += 1
                        break
                    else:
                        break
                x, y = nx, ny

print(count)