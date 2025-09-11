t = int(input())

for tc in range(1, t+1):
    print(f'#{tc}', end=' ')

    def dfs(x, y, s):
        if len(s) == 6:
            made.add(s+board[x][y])
        else:
            for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                nx, ny = x+dx, y+dy
                if 0<=nx<4 and 0<=ny<4:
                    dfs(nx, ny, s+board[x][y])
                

    board = [list(input().rstrip().split()) for _ in range(4)]
    made = set()
    for i in range(4):
        for j in range(4):
            dfs(i, j, '')
    print(len(made))