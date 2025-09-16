import sys
from collections import deque

n = int(sys.stdin.readline())
board_start = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]


def move(direction, board):
    trans = {0:(1, 0), 1:(0, 1), 2:(-1, 0), 3:(0, -1)}
    check_board = [[False for _ in range(n)] for _ in range(n)]
    ans_board = [[0 for _ in range(n)] for _ in range(n)]
    if direction == 0:
        for j in range(n):
            for i in range(n-1, -1, -1):
                data = board[i][j]
                if data == 0:
                    continue
                else:
                    x, y = i, j
                    queue = deque([(x, y)])
                    dx, dy = trans[direction]
                    while queue:
                        x, y = queue.popleft()
                        nx, ny = x+dx, y+dy
                        if 0<=nx<n and 0<=ny<n:
                            if not ans_board[nx][ny]:
                                queue.append((nx, ny))
                            if ans_board[nx][ny] == data and not check_board[nx][ny]:
                                x, y = nx, ny
                                data *= 2
                                check_board[x][y] = True
                                break
                    ans_board[x][y] = data
    elif direction == 1:
        for i in range(n):
            for j in range(n-1, -1, -1):
                data = board[i][j]
                if data == 0:
                    continue
                else:
                    x, y = i, j
                    queue = deque([(x, y)])
                    dx, dy = trans[direction]
                    while queue:
                        x, y = queue.popleft()
                        nx, ny = x+dx, y+dy
                        if 0<=nx<n and 0<=ny<n:
                            if not ans_board[nx][ny]:
                                queue.append((nx, ny))
                            if ans_board[nx][ny] == data and not check_board[nx][ny]:
                                x, y = nx, ny
                                data *= 2
                                check_board[x][y] = True
                                break
                    ans_board[x][y] = data
    elif direction == 2:
        for j in range(n):
            for i in range(n):
                data = board[i][j]
                if data == 0:
                    continue
                else:
                    x, y = i, j
                    queue = deque([(x, y)])
                    dx, dy = trans[direction]
                    while queue:
                        x, y = queue.popleft()
                        nx, ny = x+dx, y+dy
                        if 0<=nx<n and 0<=ny<n:
                            if not ans_board[nx][ny]:
                                queue.append((nx, ny))
                            if ans_board[nx][ny] == data and not check_board[nx][ny]:
                                x, y = nx, ny
                                data *= 2
                                check_board[x][y] = True
                                break
                    ans_board[x][y] = data
    elif direction == 3:
        for i in range(n):
            for j in range(n):
                data = board[i][j]
                if data == 0:
                    continue
                else:
                    x, y = i, j
                    queue = deque([(x, y)])
                    dx, dy = trans[direction]
                    while queue:
                        x, y = queue.popleft()
                        nx, ny = x+dx, y+dy
                        if 0<=nx<n and 0<=ny<n:
                            if not ans_board[nx][ny]:
                                queue.append((nx, ny))
                            if ans_board[nx][ny] == data and not check_board[nx][ny]:
                                x, y = nx, ny
                                data *= 2
                                check_board[x][y] = True
                                break
                    ans_board[x][y] = data
    return ans_board

def maximum(board):
    large = 0
    for i in range(n):
        for j in range(n):
            large = max(large, board[i][j])
    return large
directions = (0, 1, 2, 3)

largest = 0

for i in range(4**5):
    lst = []
    x = i
    while len(lst) < 5:
        lst.append(x%4)
        x //= 4
    test = board_start

    for operation in lst:
        test = move(operation, test)
    largest = max(largest, maximum(test))

print(largest)