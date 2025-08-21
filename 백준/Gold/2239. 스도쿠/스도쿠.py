import sys

def input():
    board = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(9)]
    can = []
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                can.append((i, j))
    blank = len(can)
    return board, can, blank

def able(board, position):
    def index(x):
        if 0 <= x < 3:
            return 0
        elif 3 <= x < 6:
            return 3
        else:
            return 6
    x, y = position
    i = index(x)
    j = index(y)
    unable = set()
    unable = unable | set(board[x])
    for k in range(9):
        unable.add(board[k][y])
    for nx in range(i, i+3):
        for ny in range(j, j+3):
            unable.add(board[nx][ny])
    return sorted(list(set([i for i in range(1, 10)])-unable))

board, can, blank = input()

idx = 0

while idx < blank:
    x, y = can[idx]
    data = board[x][y]
    board[x][y] = 0
    lst = able(board, (x, y))

    if len(lst) == 0:
        idx -= 1
        continue

    if data == 0:
        board[x][y] = lst[0]
        idx += 1
    elif data > 0:
        i = lst.index(data)
        
        if data == lst[-1]:
            board[x][y] = 0
            idx -= 1
        else:
            board[x][y] = lst[i+1]
            idx += 1

for i in range(8):
    sys.stdout.write(''.join(map(str, board[i])))
    sys.stdout.write('\n')
sys.stdout.write(''.join(map(str, board[8])))