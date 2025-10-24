import sys

n = int(sys.stdin.readline())
nums = []
for _ in range(n):
    num = sys.stdin.readline().rstrip()
    nums.append([int(num), 10**(len(num))])
k = int(sys.stdin.readline())
dp = [[0 for _ in range(k)] for _ in range(1<<n)]

for i in range(n):
    nums[i][0] %= k
    nums[i][1] %= k

ans = 0
dp[0][0] = 1

for state in range(1<<n):
    for loss in range(k):
        if dp[state][loss] == 0:
            continue
        for i in range(n):
            if not (state & (1<<i)):
                dp[state|(1<<i)][(loss*nums[i][1] + nums[i][0])%k] += dp[state][loss]

ans = dp[(1<<n)-1][0]

mom = 1
cal = [[1], [1], [2], [3], [2, 2], [5], [2, 3], [7], [2, 2, 2],
       [3, 3], [2, 5], [11], [2, 2, 3], [13], [2, 7], [3, 5]]

for num in range(2, n+1):
    for i in cal[num]:
        if ans%i:
            mom *= i
        else:
            ans //= i

print(f"{ans}/{mom}")