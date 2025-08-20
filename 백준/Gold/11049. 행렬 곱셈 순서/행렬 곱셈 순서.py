import sys
from collections import deque

n = int(sys.stdin.readline())
lst = []
r, c = map(int, sys.stdin.readline().split())
lst.append(r)
lst.append(c)

for _ in range(n-1):
    r, c = map(int, sys.stdin.readline().split())
    lst.append(c)

dp = [[None]*n for _ in range(n)]
queue = deque([])
for i in range(n):
    dp[i][i] = 0
    queue.append((i, i))

while queue:
    x, y = queue.popleft()
    nx, ny = x, y+1
    if nx <= ny < n and not dp[nx][ny]:
        minimum = float('inf')
        for k in range(nx, ny):
            minimum = min(minimum, dp[nx][k] + dp[k+1][ny] + lst[nx]*lst[k+1]*lst[ny+1])
        dp[nx][ny] = minimum
        queue.append((nx, ny))

print(dp[0][-1])