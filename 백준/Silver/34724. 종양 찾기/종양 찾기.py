import sys

n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]

ans = 0

for i in range(n-1):
    for j in range(m-1):
        if board[i][j]*board[i+1][j]*board[i][j+1]*board[i+1][j+1] == 1:
            ans = 1
            break
    if ans == 1:
        break

print(ans)