t = int(input())

for tc in range(1, t+1):
    n = int(input())

    board = [[None]*n for _ in range(n)]

    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    x, y = 0, 0
    direction = (0,1)
    num = 1

    for _ in range(n**2):
        board[x][y] = num
        num += 1
        nx = x + direction[0]
        ny = y + direction[1]
        if nx < 0 or ny < 0 or nx == n or ny == n or board[nx][ny] != None:
            direction = (direction[1], -direction[0])
        x += direction[0]
        y += direction[1]
    
    print(f'#{tc}')
    for i in range(n):
        print(' '.join(list(map(str, board[i]))))