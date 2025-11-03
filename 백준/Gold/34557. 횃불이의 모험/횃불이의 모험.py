import sys

def init(n):
    global board, start, key
    board = []
    for i in range(n):
        board.append(list(map(int, sys.stdin.readline().split())))
        for j in range(n):
            if board[i][j] == 2:
                start = (i, j)
    btns = ['W', 'A', 'S', 'D']
    key = {}
    for btn in btns:
        key[btn] = sys.stdin.readline().rstrip()

def run(m):
    global direction
    direction = {'W':(-1, 0), 'A':(0, -1), 'S':(1, 0), 'D':(0, 1)}
    sort = {'W':0, 'A':1, 'S':2, 'D':3, 'X': 4}
    orders = list(sys.stdin.readline().rstrip())
    before = 'X'
    x, y = start
    for order in orders:
        if order == before:
            x, y = Stay(order, x, y)
        if order != before:
            if sort[order]<=sort[before]:
                x, y = Down(order, x, y)
                x, y = Up(before, x, y)
            else:
                x, y = Up(before, x, y)
                x, y = Down(order, x, y)
        before = order
    return x+1, y+1

def Up(order: str, x, y):
    if order not in direction or key[order] != 'Up':
        return x, y
    dx, dy = direction[order]
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<n and board[nx][ny] != 1:
        return nx, ny
    return x, y

def Stay(order: str, x, y):
    if key[order] != 'Stay':
        return x, y
    dx, dy = direction[order]
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<n and board[nx][ny] != 1:
        return nx, ny
    return x, y

def Down(order: str, x, y):
    if key[order] != 'Down':
        return x, y
    dx, dy = direction[order]
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<n and board[nx][ny] != 1:
        return nx, ny
    return x, y

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    init(n)
    x, y = run(m)
    print(x, y)