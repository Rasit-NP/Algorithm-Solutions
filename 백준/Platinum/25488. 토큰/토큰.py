import sys
sys.setrecursionlimit(1<<20)

def init(n, m):
    global edges, p, a, b, node_cnt, scc_cnt, low, ids, SCCs, stack, on_stack
    edges = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v = map(int, sys.stdin.readline().split())
        edges[u].append(v)
    p = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    node_cnt = 0
    scc_cnt = 0
    low = [0]*(n+1)
    ids = [0]*(n+1)
    SCCs = [0]*(n+1)
    stack = []
    on_stack = [False]*(n+1)

def dfs(x):
    global node_cnt, scc_cnt
    node_cnt += 1
    low[x] = ids[x] = node_cnt
    stack.append(x)
    on_stack[x] = True

    for nx in edges[x]:
        if not ids[nx]:
            dfs(nx)
            low[x] = min(low[x], low[nx])
        elif on_stack[nx]:
            low[x] = min(low[x], ids[nx])
    
    if low[x] == ids[x]:
        scc_cnt += 1
        while stack:
            pos = stack.pop()
            on_stack[pos] = False
            SCCs[pos] = scc_cnt
            if pos == x:
                break

def cal(a, b, SCCs):
    length = len(SCCs)
    check = [0]*(length+1)
    res = True
    for i in range(p):
        check[SCCs[a[i]]] += 1
        check[SCCs[b[i]]] -= 1
    for i in range(length+1):
        if check[i] != 0:
            res = False
            break
    return res

if __name__ =="__main__":
    n, m = map(int, sys.stdin.readline().split())
    init(n, m)
    for i in range(1, n+1):
        if not ids[i]:
            dfs(i)
    res = cal(a, b, SCCs)
    if res:
        print('YES')
    else:
        print('NO')