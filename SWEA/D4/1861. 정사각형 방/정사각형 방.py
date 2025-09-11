t = int(input())

for tc in range(1, t+1):
    print(f'#{tc}', end=' ')

    def ans(x, y):
        if dp[x][y] is not None:
            return dp[x][y]
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<n and board[nx][ny] == board[x][y] + 1:
                if dp[nx][ny] is None:
                    dp[x][y] = ans(nx, ny) + 1
                    return dp[x][y]
                else:
                    dp[x][y] = dp[nx][ny] + 1
                    return dp[x][y]
        dp[x][y] = 0
        return 0

    n = int(input())
    board = [list(map(int, input().split())) for _ in range(n)]
    dp = [[None for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if dp[i][j]:
                continue
            else:
                ans(i, j)
    maximum = 0
    ans_fin = float('inf')
    for i in range(n):
        for j in range(n):
            if dp[i][j] > maximum:
                maximum = dp[i][j]
                ans_fin = board[i][j]
            elif dp[i][j] == maximum:
                ans_fin = min(ans_fin, board[i][j])
    print(ans_fin, maximum+1)