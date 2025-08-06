t = int(input())

for tc in range(1, t+1):
    n, m = map(int, input().split())

    board = [None]*n
    for i in range(n):
        board[i] = list(map(int, input().split()))
    
    maximum = 0

    for i in range(n):
        for j in range(n):
            sum = board[i][j]
            dx = [1, -1, 0, 0]
            dy = [0, 0, 1, -1]
            for d in range(4):
                for power in range(1,m):
                    x = i+dx[d]*power
                    y = j+dy[d]*power
                    if 0<=x<n and 0<=y<n:
                        sum += board[x][y]
            maximum = max(maximum, sum)

            sum = board[i][j]
            dx = [1, 1, -1, -1]
            dy = [1, -1, 1, -1]
            for d in range(4):
                for power in range(1,m):
                    x = i+dx[d]*power
                    y = j+dy[d]*power
                    if 0<=x<n and 0<=y<n:
                        sum += board[x][y]
            maximum = max(maximum, sum)
    
    print(f'#{tc}', maximum)