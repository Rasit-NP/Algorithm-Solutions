import sys

def input():
    n, m, q = map(int, sys.stdin.readline().split())
    board = [[0 for _ in range(m+1)]]
    for _ in range(n):
        board.append([0]+list(map(int, sys.stdin.readline().split())))
    starts = [tuple(map(int, sys.stdin.readline().split())) for _ in range(q)]

    return n, m, q, board, starts

n, m, q, board, starts = input()

dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
for j in range(1, m+1):
    dp[1][j] = board[1][j]

for i in range(2, n+1):
    for j in range(1, m+1):
        dp[i][j] = board[i][j] + dp[i-1][j-1] + dp[i-1][j] - dp[i-2][j-1]

for x, y in starts:
    sys.stdout.write(str(dp[x][y])+'\n')