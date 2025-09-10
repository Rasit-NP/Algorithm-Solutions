import sys

n = int(sys.stdin.readline())
edges = [set() for _ in range(n+1)]

for i in range(1, n+1):
    l, r = map(int, sys.stdin.readline().split())
    edges[l].add(i)
    edges[r].add(i)

dp = [[False for _ in range(n+1)] for _ in range(100)]

dp[0][1] = True
ans = 0
for k in range(1, 100):
    for i in range(1, n+1):
        for edge in edges[i]:
            if dp[k-1][edge]:
                dp[k][i] = True
                break
    if k>=10:
        if dp[k][1]:
            continue
        else:
            ans = k
            break

if ans:
    print(ans)
else:
    print(-1)