import sys

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
        scc = []
        while True:
            node = stack.pop()
            on_stack[node] = False
            scc.append(node)
            if node == x:
                break
        SCCs.append(scc)

n = int(sys.stdin.readline())
costs = list(map(int, sys.stdin.readline().split()))
edges = [[] for _ in range(n)]

for i in range(n):
    inputs = sys.stdin.readline().rstrip()
    for j in range(n):
        if inputs[j] == '1':
            edges[i].append(j)

node_cnt = 0
ids = [0] * n
low = [0] * n
on_stack = [False] * n
stack = []
SCCs = []

for i in range(n):
    if not ids[i]:
        dfs(i)

ans = 0
for scc in SCCs:
    minimum = float('inf')
    for node in scc:
        minimum = min(minimum, costs[node])
    ans += minimum

print(ans)