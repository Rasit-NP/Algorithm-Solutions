import sys
sys.setrecursionlimit(1<<20)

def init(d, l):
    global edges, node_cnt, ids, low, on_stack, stack, SCCs
    edges = [[] for _ in range(d+1)]

    for _ in range(l):
        a, b = map(int, sys.stdin.readline().split())
        edges[a].append(b)
    node_cnt = 0
    ids = [0] * (d+1)
    low = [0] * (d+1)
    on_stack = [False] * (d+1)
    stack = []
    SCCs = []

def dfs(x):
    global node_cnt
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
    
    if ids[x] == low[x]:
        cnt = 0
        while True:
            node = stack.pop()
            on_stack[node] = False
            cnt += 1
            if node == x:
                break
        SCCs.append(cnt)

if __name__ == "__main__":
    d = int(sys.stdin.readline())
    l = int(sys.stdin.readline())
    init(d, l)
    for i in range(1, d+1):
        if not ids[i]:
            dfs(i)
    print(max(SCCs))