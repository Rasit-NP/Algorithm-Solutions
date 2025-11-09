import sys

n, m = map(int, sys.stdin.readline().split())
board = [[0]*m for _ in range(n)]

x = 1
for i in range(n//2):
    for j in range(m//2):
        board[i][j] = x
        x += 1
for i in range(n//2):
    for j in range(m//2, m):
        board[i][j] = board[i][m-j-1]

for i in range(n//2, n):
    for j in range(m):
        board[i][j] = board[n-i-1][j]

for i in range(n):
    sys.stdout.write(' '.join(map(str, board[i])))
    sys.stdout.write('\n')