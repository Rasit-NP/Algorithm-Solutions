import sys

n = int(sys.stdin.readline())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
white = []
black = []
blank_white = 0
blank_black = 0
changed_white = 0
changed_black = 0
ans = 0
for i in range(n):
    for j in range(n):
        if board[i][j] == 1:
            if (i+j)%2 == 0:
                white.append((i, j))
                blank_white += 1
                changed_white += 1
            else:
                black.append((i, j))
                blank_black += 1
                changed_black += 1

idx = 0
data = [None] * blank_white
maximum = 0
count = 0
going = 1
while 0<= idx <= blank_white:
    if idx == blank_white:
        maximum = max(maximum, count)
        idx -= 1
        going = 0
        continue
    if going == 1 and maximum-count >= changed_white:
        idx -= 1
        going = 0
        continue
    if data[idx] == None:
        x, y = white[idx]
        if board[x][y] == 1:
            data[idx] = 1
            for dx, dy in ((1, 1), (1, -1)):
                for k in range(1, n-x):
                    nx, ny = x+dx*k, y+dy*k
                    if 0 <= ny < n:
                        board[nx][ny] -= 1
                        if board[nx][ny] == 0:
                            changed_white -= 1
            changed_white -= 1
            count += 1
            idx += 1
            going = 1
        else:
            data[idx] = 0
            idx += 1
            going = 1
    elif data[idx] == 1:
        x, y = white[idx]
        data[idx] = 0
        for dx, dy in ((1, 1), (1, -1)):
                for k in range(1, n-x):
                    nx, ny = x+dx*k, y+dy*k
                    if 0 <= ny < n:
                        board[nx][ny] += 1
                        if board[nx][ny] == 1:
                            changed_white += 1
        changed_white += 1
        count -= 1
        idx += 1
        going = 1
    elif data[idx] == 0:
        data[idx] = None
        idx -= 1
        going = 0

ans += maximum

idx = 0
data = [None] * blank_black
maximum = 0
count = 0
going = 1
while 0<= idx <= blank_black:
    if idx == blank_black:
        maximum = max(maximum, count)
        idx -= 1
        going = 0
        continue
    if going == 1 and maximum-count >= changed_black:
        idx -= 1
        going = 0
        continue
    if data[idx] == None:
        x, y = black[idx]
        if board[x][y] == 1:
            data[idx] = 1
            for dx, dy in ((1, 1), (1, -1)):
                for k in range(1, n-x):
                    nx, ny = x+dx*k, y+dy*k
                    if 0 <= ny < n:
                        board[nx][ny] -= 1
                        if board[nx][ny] == 0:
                            changed_black -= 1
            changed_black -= 1
            count += 1
            idx += 1
            going = 1
        else:
            data[idx] = 0
            idx += 1
            going = 1
    elif data[idx] == 1:
        x, y = black[idx]
        data[idx] = 0
        for dx, dy in ((1, 1), (1, -1)):
                for k in range(1, n-x):
                    nx, ny = x+dx*k, y+dy*k
                    if 0 <= ny < n:
                        board[nx][ny] += 1
                        if board[nx][ny] == 1:
                            changed_black += 1
        changed_black += 1
        count -= 1
        idx += 1
        going = 1
    elif data[idx] == 0:
        data[idx] = None
        idx -= 1
        going = 0
ans += maximum

print(ans)