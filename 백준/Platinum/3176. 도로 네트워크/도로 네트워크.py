import sys, math
from collections import deque

def init(n):
    global LOG, edges, depth, parents, dist_parents
    LOG = int(math.log2(n)) + 1
    edges = [[] for _ in range(n+1)]
    depth = [None for _ in range(n+1)]
    parents = [[-1]*(LOG+1) for _ in range(n+1)]
    dist_parents = [[[None, None] for _ in range(LOG+1)] for _ in range(n+1)]
    
    for _ in range(n-1):
        a, b, c = map(int, sys.stdin.readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))

def bfs(n, edges):
    queue = deque([])
    queue.append(1)
    parents[1][0] = 0
    depth[1] = 0
    dist_parents[1][0] = [float('inf'), 0]
    while queue:
        x = queue.popleft()
        for nx, dist in edges[x]:
            if parents[nx][0] == -1:
                parents[nx][0] = x
                dist_parents[nx][0] = [dist, dist]
                depth[nx] = depth[x]+1
                queue.append(nx)

def change(parents, dist_parents):
    for k in range(1, LOG+1):
        for x in range(1, n+1):
            if parents[x][k-1] == 0:
                parents[x][k] = 0
                dist_parents[x][k] = [dist_parents[x][k-1][0], dist_parents[x][k-1][1]]
                continue
            parents[x][k] = parents[parents[x][k-1]][k-1]
            dist_parents[x][k][0] = min(dist_parents[parents[x][k-1]][k-1][0], dist_parents[x][k-1][0])
            dist_parents[x][k][1] = max(dist_parents[parents[x][k-1]][k-1][1], dist_parents[x][k-1][1])

def query(m):
    def LCA(a, b):
        minimum_a = float('inf')
        minimum_b = float('inf')
        maximum_a = 0
        maximum_b = 0
        if depth[a] < depth[b]:
            a, b = b, a
        diff = depth[a] - depth[b]
        for k in range(LOG+1):
            if diff & (1<<k):
                minimum_a = min(minimum_a, dist_parents[a][k][0])
                maximum_a = max(maximum_a, dist_parents[a][k][1])
                a = parents[a][k]
        if a == b:
            print(minimum_a, maximum_a)
            return
        for k in range(LOG, -1, -1):
            if parents[a][k] == parents[b][k]:
                continue
            minimum_a = min(minimum_a, dist_parents[a][k][0])
            maximum_a = max(maximum_a, dist_parents[a][k][1])
            minimum_b = min(minimum_b, dist_parents[b][k][0])
            maximum_b = max(maximum_b, dist_parents[b][k][1])
            a = parents[a][k]
            b = parents[b][k]
        minimum_a = min(minimum_a, dist_parents[a][k][0])
        maximum_a = max(maximum_a, dist_parents[a][k][1])
        minimum_b = min(minimum_b, dist_parents[b][k][0])
        maximum_b = max(maximum_b, dist_parents[b][k][1])
        minimum = min(minimum_a, minimum_b)
        maximum = max(maximum_a, maximum_b)
        print(minimum, maximum)
    
    for _ in range(m):
        d, e = map(int, sys.stdin.readline().split())
        LCA(d, e)

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    init(n)
    bfs(n, edges)
    change(parents, dist_parents)

    m = int(sys.stdin.readline())
    query(m)