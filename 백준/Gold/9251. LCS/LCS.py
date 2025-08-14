import sys

str1 = sys.stdin.readline().rstrip()
str2 = sys.stdin.readline().rstrip()

len1 = len(str1)
len2 = len(str2)

dp = [[0] * len2 for _ in range(len1)]

if str1[0] == str2[0]:
    dp[0][0] = 1
for i in range(1, len1):
    if str1[i] == str2[0]:
        dp[i][0] = 1
    else:
        dp[i][0] = min(1, dp[i-1][0])
for j in range(1, len2):
    if str1[0] == str2[j]:
        dp[0][j] = 1
    else:
        dp[0][j] = min(1, dp[0][j-1])


for i in range(1, len1):
    for j in range(1, len2):
        if str1[i] == str2[j]:
            dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]))
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[len1-1][len2-1])