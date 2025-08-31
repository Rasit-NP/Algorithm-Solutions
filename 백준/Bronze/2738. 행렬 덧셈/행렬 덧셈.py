import sys

n, m = map(int, sys.stdin.readline().split())

board1 = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

board2 = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

ans = [[None]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        ans[i][j] = board1[i][j] + board2[i][j]

for i in range(n):
    print(' '.join(map(str, ans[i])))