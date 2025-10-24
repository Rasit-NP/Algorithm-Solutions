import sys
sys.setrecursionlimit(1<<20)

v, e = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(v+1)]

for _ in range(e):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)

id_cnt = 0
ids = [0] * (v+1)
low = [0] * (v+1)
on_stack = [False] * (v+1)
stack = []
SCCs = []
cnt = 0

def dfs(x):
    global id_cnt, cnt
    id_cnt += 1
    ids[x] = low[x] = id_cnt
    stack.append(x)
    on_stack[x] = True

    for nx in edges[x]:
        if ids[nx] == 0:
            dfs(nx)
            low[x] = min(low[x], low[nx])
        elif on_stack[nx]:
            low[x] = min(low[x], ids[nx])
    
    if low[x] == ids[x]:
        scc = []
        while True:
            node = stack.pop()
            on_stack[node] = False
            scc.append(node)
            if node == x:
                break
        cnt += 1
        SCCs.append(scc)

for i in range(1, v+1):
    if ids[i] == 0:
        dfs(i)

SCCs.sort(key=lambda x: min(x))

print(cnt)
for scc in SCCs:
    scc.sort()
    print(' '.join(map(str, scc))+' -1')