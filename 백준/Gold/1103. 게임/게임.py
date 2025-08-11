import sys

n ,m = map(int, sys.stdin.readline().split())

board = [None] * n

for i in range(n):
    board[i] = list(sys.stdin.readline().rstrip())
    for j in range(m):
        if board[i][j] != 'H':
            board[i][j] = int(board[i][j])


dp = [[0]*m for _ in range(n)]
visited = [[None]*m for _ in range(n)]
cycle = False

def dfs(x,y):
    global cycle
    if not (0<=x<n and 0<=y<m) or board[x][y] == 'H':
        return 0
    if visited[x][y]:
        cycle = True
        return 0
    if dp[x][y] != 0:
        return dp[x][y]
    
    visited[x][y] = True
    power = board[x][y]
    best = 0
    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = x+dx*power, y + dy*power
        val = dfs(nx, ny) + 1
        if cycle:
            return 0
        if val > best:
            best = val
    
    dp[x][y] = best
    visited[x][y] = False
    return dp[x][y]

ans = dfs(0, 0)

if cycle:
    print(-1)
else:
    print(ans)