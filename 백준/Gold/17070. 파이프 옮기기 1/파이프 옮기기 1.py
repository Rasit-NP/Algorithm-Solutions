import sys

n = int(sys.stdin.readline())
home = []
visited = [[[0,0,0] for _ in range(n)] for _ in range(n)]
visited[0][1] = [1,0,0]     ## 경로갯수벡터 [가로, 세로, 대각]
visited[0][0] = [1,0,0]
for _ in range(n):
    home.append(list(map(int, sys.stdin.readline().split())))

for i in range(n):
    for j in range(n):
        if (i,j) != (0,0) and home[i][j] == 0:
            ## 가로로 온 놈
            if j>0 and home[i][j-1] == 0:
                visited[i][j][0] = visited[i][j-1][0]+visited[i][j-1][2]

            ## 세로로 온 놈
            if i>0 and home[i-1][j] == 0 and j != 0:
                visited[i][j][1] = visited[i-1][j][1]+visited[i-1][j][2]

            ## 대각으로 온 놈
            if i>0 and j>0 and home[i-1][j] == 0 and home[i][j-1] == 0 and home[i-1][j-1] == 0:
                if i == 1 and j == 1:
                    continue
                else:
                    visited[i][j][2] = sum(visited[i-1][j-1])

print(sum(visited[-1][-1]))
