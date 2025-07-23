import sys
sys.setrecursionlimit(10**6)

def dfs(x, y, color):
    visited[x][y] = True
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<n and not visited[nx][ny] and art[nx][ny] == color:
            dfs(nx, ny, color)

def dfsRG(x, y):
    visited2[x][y] = True
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<n and not visited2[nx][ny] and art[nx][ny] != 'B':
            dfsRG(nx, ny)

n = int(sys.stdin.readline())
art = [0]*n
visited = [[False]*n for _ in range(n)]
visited2 = [[False]*n for _ in range(n)]
countR = 0
countG = 0
countB = 0
countRG = 0

for i in range(n):
    art[i] = list(sys.stdin.readline().rstrip())

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            if art[i][j] == 'R':
                dfs(i,j,'R')
                countR += 1
            elif art[i][j] == 'G':
                dfs(i,j,'G')
                countG += 1
            elif art[i][j] == 'B':
                dfs(i,j,'B')
                countB += 1
        if not visited2[i][j]:
            if art[i][j] !='B':
                dfsRG(i,j)
                countRG += 1

print(f'{countR+countG+countB} {countRG+countB}')