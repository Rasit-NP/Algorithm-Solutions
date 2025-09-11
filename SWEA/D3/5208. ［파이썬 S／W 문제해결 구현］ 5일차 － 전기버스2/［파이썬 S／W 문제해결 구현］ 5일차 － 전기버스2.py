t = int(input())

for tc in range(1, t+1):
    
    nums = list(map(int, input().split()))
    n = nums.pop(0)
    print(f'#{tc}', end=' ')
    dp = [float('inf') for _ in range(n)]
    dp[0] = 0
    r = nums[0]
    for i in range(1, r+1):
        dp[i] = 0
    for x in range(1, n-1):
        r = nums[x]
        for dx in range(1, r+1):
            nx = x+dx
            if nx < n and dp[nx] > dp[x] + 1:
                dp[nx] = dp[x] + 1

    print(dp[-1])
