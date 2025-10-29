import sys

def init(n):
    global board, left_dp, right_dp, a, b, c, d
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(2)]
    left_dp = [0]*n
    right_dp = [0]*n
    a, b, c, d = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1
    c -= 1
    d -= 1
    if a>c:
        a, c = c, a
        b, d = d, b

def sum_left(a):
    left_dp[0] = max(board[0][0], board[1][0], board[1][0]+board[0][0])
    for i in range(1, a+1):
        left_dp[i] = max(board[0][i], board[1][i], board[0][i]+board[1][i], left_dp[i-1]+board[0][i]+board[1][i])

def sum_right(b):
    right_dp[-1] = max(board[0][-1], board[1][-1], board[1][-1]+board[0][-1])
    for i in range(n-2, b-1, -1):
        right_dp[i] = max(board[0][i], board[1][i], board[0][i]+board[1][i], right_dp[i+1]+board[0][i]+board[1][i])

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        init(n)
        sum_left(a)
        sum_right(c)
        sum = 0
        if a != c:
            left = max(board[b][a], board[b][a]+board[not b][a])
            if a > 0:
                left = max(left, left_dp[a-1]+board[b][a]+board[not b][a])
            right = max(board[d][c], board[d][c]+board[not d][c])
            if c < n-1:
                right = max(right, right_dp[c+1]+board[d][c]+board[not d][c])
            sum += left+right
            for i in range(a+1, c):
                sum += max(board[0][i], board[1][i], board[0][i]+board[1][i])
        elif a == c:
            left = 0; right = 0
            if a > 0: left = max(0, left_dp[a-1])
            if c < n-1: right = max(0, right_dp[c+1])
            sum = max(0, left, right) + board[b][a] + board[d][c]
        print(sum)