import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())

    board = [None, None]
    board[0] = list(map(int, sys.stdin.readline().split()))
    board[1] = list(map(int, sys.stdin.readline().split()))

    ans = [[None]*n, [None]*n]
    ans[0][0], ans[1][0] = board[0][0], board[1][0]
    if n==1:
        print(max(ans[0][0], ans[1][0]))
        continue
    ans[0][1], ans[1][1] = ans[1][0] + board[0][1], ans[0][0] + board[1][1]

    for i in range(2, n):
        ans[0][i] = max(ans[1][i-1]+board[0][i], max(ans[0][i-2], ans[1][i-2])+board[0][i])
        ans[1][i] = max(ans[0][i-1]+board[1][i], max(ans[0][i-2], ans[1][i-2])+board[1][i])

    print(max(ans[0][-1], ans[1][-1]))