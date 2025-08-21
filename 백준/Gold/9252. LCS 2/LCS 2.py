import sys

str1 = sys.stdin.readline().rstrip()
str2 = sys.stdin.readline().rstrip()

len1 = len(str1)
len2 = len(str2)

dp = [[None]*len2 for _ in range(len1)]

if str1[0] == str2[0]:
    dp[0][0] = (1, str1[0])
else:
    dp[0][0] = (0, '')

for j in range(1, len2):
    if str1[0] == str2[j]:
        dp[0][j] = (1, str1[0])
    else:
        dp[0][j] = (dp[0][j-1][0], dp[0][j-1][1])

for i in range(1, len1):
    if str1[i] == str2[0]:
        dp[i][0] = (1, str2[0])
    else:
        dp[i][0] = (dp[i-1][0][0], dp[i-1][0][1])

for i in range(1, len1):
    for j in range(1, len2):
        a0, a1 = dp[i-1][j-1]
        b0, b1 = dp[i][j-1]
        c0, c1 = dp[i-1][j]
        if str1[i] == str2[j]:
            maximum = max(a0+1, b0, c0)
            if maximum == a0+1:
                dp[i][j] = (maximum, a1+str1[i])
            elif maximum == b0:
                dp[i][j] = (maximum, b1)
            elif maximum == c0:
                dp[i][j] = (maximum, c1)
        else:
            maximum = max(a0, b0, c0)
            if maximum == a0:
                dp[i][j] = (maximum, a1)
            elif maximum == b0:
                dp[i][j] = (maximum, b1)
            elif maximum == c0:
                dp[i][j] = (maximum, c1)

ans = dp[-1][-1]
print(ans[0])
if ans[0]:
    print(ans[1])