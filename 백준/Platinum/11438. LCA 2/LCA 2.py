import sys
from collections import deque

def init(n):
    global edges, parents, degrees
    edges = [[] for _ in range(n+1)]
    parents = [[None]*(21) for _ in range(n+1)]
    degrees = [None for _ in range(n+1)]
    degrees[1] = 0
    parents[1][0] = 0

    for _ in range(n-1):
        a, b = map(int, sys.stdin.readline().split())
        edges[a].append(b)
        edges[b].append(a)

def bfs(edges):
    queue = deque([])
    queue.append(1)

    while queue:
        x = queue.popleft()
        for nx in edges[x]:
            if parents[nx][0] is None:
                parents[nx][0] = x
                queue.append(nx)
                degrees[nx] = degrees[x] + 1
    edges.clear()

def dp(parents):
    for k in range(1, 21):
        for x in range(1, n+1):
            if parents[x][k-1] is not None:
                parents[x][k] = parents[parents[x][k-1]][k-1]

def LCA(degrees, parents, a, b):
    # b의 차수가 더 깊다면
    if degrees[a] < degrees[b]:
        a, b = b, a
    diff = degrees[a] - degrees[b]
    for k in range(21):
        if diff&(1<<k):
            a = parents[a][k]
    if a == b:
        print(a)
        return
    for k in range(20, -1, -1):
        if parents[a][k] is not None and parents[b][k] is not None:
            if parents[a][k] != parents[b][k]:
                a = parents[a][k]
                b = parents[b][k]
    print(parents[a][0])

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    init(n)
    bfs(edges)
    dp(parents)

    m = int(sys.stdin.readline())
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        LCA(degrees, parents, a, b)