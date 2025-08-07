import sys

n, m = map(int, sys.stdin.readline().split())

board = []
sample = [[None]*n for _ in range(n)]

for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))

sample[0][0] = board[0][0]
for j in range(1, n):
    sample[0][j] = sample[0][j-1] + board[0][j]
for i in range(1, n):
    sample[i][0] = sample[i-1][0] + board[i][0]
    for j in range(1, n):
        sample[i][j] = sample[i][j-1] + sample[i-1][j] + board[i][j] - sample[i-1][j-1]



for _ in range(m):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    x1, y1, x2, y2 = x1-1, y1-1, x2-1, y2-1
    if x1 > 0 and y1 > 0:
        ans = sample[x2][y2] - sample[x1-1][y2] - sample[x2][y1-1] + sample[x1-1][y1-1]
    elif x1 == 0 and y1 > 0:
        ans = sample[x2][y2] - sample[x2][y1-1]
    elif y1 == 0 and x1 > 0:
        ans = sample[x2][y2] - sample[x1-1][y2]
    elif x1 == 0 and y1 == 0:
        ans = sample[x2][y2]
    
    print(ans)