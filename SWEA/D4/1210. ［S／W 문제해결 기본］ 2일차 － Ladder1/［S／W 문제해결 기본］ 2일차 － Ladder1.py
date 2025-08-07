for _ in range(10):
    tc = int(input())

    board = []
    lines = []
    for _ in range(100):
        board.append(list(map(int, input().split())))
    for i in range(100):
        if board[99][i] == 1:
            lines.append(i)
        elif board[99][i] == 2:
            lines.append(i)
            start = (99, i)
    
    x = start[0]
    y = start[1]
    while x > 0:
        x -= 1
        dy = [-1, 1]
        for i in dy:
            ny = y + i
            if 0<=ny<100 and board[x][ny] == 1:
                y = lines[lines.index(y)+i]
                break
    
    print(f'#{tc}', y)