import sys
sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
dp = [[None for _ in range(n)] for _ in range(n)]

def dfs(x, y):
    if dp[x][y] is not None:
        return dp[x][y]
    else:
        maximum = 1
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and board[nx][ny] > board[x][y]:
                maximum = max(dfs(nx, ny)+1, maximum)
        dp[x][y] = maximum
        return dp[x][y]

maximum = 0

for i in range(n):
    for j in range(n):
        maximum = max(dfs(i, j), maximum)

print(maximum)