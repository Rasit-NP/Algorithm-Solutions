import sys
sys.setrecursionlimit(1<<20)

def init(n, m):
    global edges, node_count, ids, low, on_stack, stack, SCCs
    edges = [[] for _ in range(n+1)]
    for _ in range(m):
        v, w = map(int, sys.stdin.readline().split())
        edges[v].append(w)
    node_count = 0
    ids = [0]*(n+1)
    low = [0]*(n+1)
    on_stack = [False]*(n+1)
    stack = []
    SCCs = []

def dfs(x):
    global node_count
    node_count += 1
    ids[x] = low[x] = node_count
    stack.append(x)
    on_stack[x] = True

    for nx in edges[x]:
        if not ids[nx]:
            dfs(nx)
            low[x] = min(low[x], low[nx])
        elif on_stack[nx]:
            low[x] = min(low[x], ids[nx])
    
    if ids[x] == low[x]:
        scc = []
        while True:
            a = stack.pop()
            on_stack[a] = False
            scc.append(a)
            if a == x:
                break
        SCCs.append(scc)

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    init(n, m)

    for i in range(1, n+1):
        if not ids[i]:
            dfs(i)
    
    if len(SCCs) == 1:
        print('Yes')
    else:
        print('No')