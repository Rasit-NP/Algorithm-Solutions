import sys

t = int(sys.stdin.readline())
for _ in range(t):
    k = int(sys.stdin.readline())
    nums = list(map(int, sys.stdin.readline().split()))
    dp = [[None for _ in range(k)] for _ in range(k)]
    for i in range(k):
        dp[i][i] = (0, nums[i])
    for di in range(1, k):
        for i in range(k):
            j = i+di
            if j >= k:
                break
            minimum = float('inf')
            for m in range(i, j):
                minimum = min(minimum, dp[i][m][0]+dp[m+1][j][0])
            dp[i][j] = (minimum + dp[i][j-1][1]+dp[j][j][1], dp[i][j-1][1]+dp[j][j][1])
    print(dp[0][-1][0])