import sys
sys.setrecursionlimit(1<<20)

def check(state, a, b):
    a, b = (b, a) if a>b else (a, b)
    neighbor = 1
    for i in range(a+1, b):
        if state & (1<<i):
            neighbor = 0
            break
    if neighbor:
        return True
    neighbor = 1
    for i in range(b+1, a+n):
        if i>=n:
            i -= n
        if state & (1<<i):
            neighbor = 0
            break
    if neighbor:
        return True
    return False

def dfs(state, x):
    if dp[state][x] is not None:
        return dp[state][x]
    dp[state][x] = 0
    if state == (1<<n)-1:
        if abs(start-x) != 1 and abs(start-x) != n-1:
            dp[state][x] += 1
            return dp[state][x]
        else:
            return dp[state][x]
    for nx in range(n):
        if state & (1<<nx):
            continue
        if check(state, x, nx):
            continue
        dp[state][x] += dfs(state|(1<<nx), nx)
    return dp[state][x]

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    Ps = list(map(int, sys.stdin.readline().split()))
    dp = [[None]*n for _ in range(1<<n)]
    start = Ps[0]-1

    state = 0
    for p in Ps:
        state |= 1<<(p-1)
    
    ans = dfs(state, Ps[-1]-1)
    print(ans)