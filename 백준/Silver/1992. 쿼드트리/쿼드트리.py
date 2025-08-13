import sys
sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())

board = [None] * n

for i in range(n):
    board[i] = list(map(int, list(sys.stdin.readline().rstrip())))

def func(n, r, c):
    if n == 2:
        for i in range(2):
            for j in range(2):
                if board[r][c] != board[r+i][c+j]:
                    return '('+str(board[r][c])+str(board[r][c+1])+str(board[r+1][c])+str(board[r+1][c+1])+')'
        if board[r][c] == 1:
            return '1'
        else:
            return '0'
    else:
        l = n//2
        for i in range(n):
            for j in range(n):
                if board[r][c] != board[r+i][c+j]:
                    return '(' + func(l, r, c) + func(l, r, c+l) + func(l, r+l, c) + func(l, r+l, c+l) + ')'
        if board[r][c] == 1:
            return '1'
        else:
            return '0'
print(func(n, 0, 0))