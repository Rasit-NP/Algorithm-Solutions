import sys, math

t = int(sys.stdin.readline())
for _ in range(t):
    m, n = map(int, sys.stdin.readline().split())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    maximum = -float('inf')
    max_sign = -1
    ans = 0
    pm = [None for _ in range(m)]
    for j in range(m):
        cnt_m = 0
        zero = False
        for i in range(n):
            if board[i][j] < 0:
                cnt_m += 1
            elif board[i][j] == 0:
                zero = True
                break
        if zero:
            pm[j] = 0
        elif cnt_m&1:
            pm[j] = -1
        else:
            pm[j] = 1

    for j in range(m):
        if pm[j] < max_sign:
            continue
        else:
            logsum = 0
            for i in range(n):
                if board[i][j] == 0:
                    break
                logsum += math.log(abs(board[i][j]))
            logsum *= pm[j]
            if logsum >= maximum:
                maximum = logsum
                ans = j+1
                max_sign = pm[j]
    print(ans)