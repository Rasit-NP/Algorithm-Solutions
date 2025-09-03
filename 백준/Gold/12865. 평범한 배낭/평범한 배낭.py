import sys

n, k = map(int, sys.stdin.readline().split())
items = [(0,0)]+[tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1, n+1):
    weight, value = items[i]
    for w in range(k+1):
        if weight <= w:
            dp[i][w] = max(dp[i-1][w],
                           dp[i-1][w-weight]+value)
        else:
            dp[i][w] = dp[i-1][w]

print(dp[n][k])