import sys
sys.setrecursionlimit(1<<20)

def dfs(x):
    global node_cnt, ans, find
    if X in edges[x]:
        find = True
    if find:
        return
    node_cnt += 1
    ids[x] = low[x] = node_cnt
    stack.append(x)
    on_stack[x] = True

    for nx in edges[x]:
        if not ids[nx]:
            dfs(nx)
            low[x] = min(low[x], low[nx])
        elif on_stack[nx]:
            low[x] = min(low[x], ids[nx])
    
    if low[x] == ids[x]:
        check = set()
        while stack:
            node = stack.pop()
            on_stack[node] = False
            check.add(node)
            if node == x:
                break
        if x != X:
            ans += 1

n, m, X = map(int, sys.stdin.readline().split())
edges = [set() for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    edges[b].add(a)

low = [0 for _ in range(n+1)]
ids = [0 for _ in range(n+1)]
stack = []
on_stack = [False for _ in range(n+1)]
node_cnt = 0
ans = 0

find = False
dfs(X)
for i in range(1, n+1):
    find = False
    if not ids[i]:
        dfs(i)

print(ans)