t = 10

for tc in range(1, t+1):
    n = int(input())
    board = [None] * 8
    for i in range(8):
        board[i] = list(input().rstrip())

    count = 0
    for i in range(8):
        for j in range(9-n):
            check = 1
            for k in range(n//2):
                if board[i][j+k] == board[i][j+n-k-1]:
                    continue
                else:
                    check = 0
            if check == 0:
                continue
            else:
                count += 1
    for j in range(8):
        for i in range(9-n):
            check = 1
            for k in range(n//2):
                if board[i+k][j] == board[i+n-k-1][j]:
                    continue
                else:
                    check = 0
            if check == 0:
                continue
            else:
                count += 1

    print(f'#{tc}', end=' ')
    print(count)