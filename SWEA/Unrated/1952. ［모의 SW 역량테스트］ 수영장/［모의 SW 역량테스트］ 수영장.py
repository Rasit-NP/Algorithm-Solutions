t = int(input())

for tc in range(1, t+1):
    print(f'#{tc}', end=' ')
    
    prices = list(map(int, input().split()))
    plans = list(map(int, input().split()))
    cost = [plans[i]*prices[0] for i in range(12)]
    
    for i in range(12):
        if cost[i] > prices[1]:
            cost[i] = prices[1]
    dp = [[0 for _ in range(12)] for _ in range(12)]
    for i in range(12):
        dp[i][i] = cost[i]
    
    for i in range(11):
        x, y = i, i+1
        dp[x][y] = dp[x][x] + dp[y][y]
    for i in range(10):
        dp[i][i+2] = min(prices[2], dp[i][i]+dp[i+1][i+1]+dp[i+2][i+2])

    for dif in range(3, 12):
        for i in range(12-dif):
            x, y = i, i+dif
            minimum = float('inf')
            for k in range(x, y):
                minimum = min(minimum, dp[x][k]+dp[k+1][y])
            dp[x][y] = minimum
    ans = dp[0][-1]
    if ans > prices[-1]:
        ans = prices[-1]
    print(ans)