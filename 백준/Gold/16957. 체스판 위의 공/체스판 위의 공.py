import sys

r, c = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(r)]
parents = [[None for _ in range(c)] for _ in range(r)]
ans = [[0 for _ in range(c)] for _ in range(r)]
sets = set()

for i in range(r):
    for j in range(c):
        minimum = board[i][j]
        min_i, min_j = None, None
        for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)):
            ni, nj = i+di, j+dj
            if 0<=ni<r and 0<=nj<c:
                if minimum > board[ni][nj]:
                    minimum = board[ni][nj]
                    min_i, min_j = ni, nj
        if min_i is None and min_j is None:
            parents[i][j] = (i, j)
        else:
            parents[i][j] = (min_i, min_j)

for i in range(r):
    for j in range(c):
        def compress(i, j):
            x, y = i, j
            while parents[x][y] != (x, y):
                x, y = parents[x][y]
                parents[i][j] = parents[x][y]
        compress(i, j)
        x, y = parents[i][j]
        ans[x][y] += 1

for sub in ans:
    print(' '.join(map(str, sub)))