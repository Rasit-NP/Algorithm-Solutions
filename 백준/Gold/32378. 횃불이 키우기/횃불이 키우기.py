import sys

n, k, s = map(int, sys.stdin.readline().split())
energy = list(map(int, sys.stdin.readline().split()))

if k<=37:
    dp = [[-float('inf')]*(k+1) for _ in range(n+1)] # dp[n일차][k회]
    dp[0][0] = s
    mega = 0
    for i in range(n):
        for j in range(min(i+1, k+1)):
            if dp[i][j]<=0:
                continue
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+energy[i])
            if j < k:
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]<<1)

    ans = max(dp[n])
    if ans > 100000000000:
        print('MEGA')
    elif ans <= 0:
        print(-1)
    else:
        print(ans)
else:
    print('MEGA')