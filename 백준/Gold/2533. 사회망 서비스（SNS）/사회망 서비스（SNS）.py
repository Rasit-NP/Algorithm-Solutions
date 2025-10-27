import sys
sys.setrecursionlimit(1<<20)

def dfs(x):
    visited[x] = True
    check = 1
    for nx in edges[x]:
        if visited[nx]:
            continue
        a, b = dfs(nx)
        dp[x][0] += b
        dp[x][1] += min(a, b)
        check = 0
    if check:
        dp[x][1] = 1
        dp[x][0] = 0
    else:
        dp[x][1] += 1
    return dp[x]

n = int(sys.stdin.readline())
edges = [[] for _ in range(n+1)]
visited = [False] * (n+1)
for _ in range(n-1):
    u, v = map(int, sys.stdin.readline().split())
    edges[u].append(v)
    edges[v].append(u)

dp = [[0] * 2 for _ in range(n+1)]
ans = min(dfs(1))
print(ans)