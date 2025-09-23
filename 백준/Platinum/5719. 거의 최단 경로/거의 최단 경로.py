import sys
import heapq
from collections import deque

INF = 10**18
input = sys.stdin.readline

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break

    s, d = map(int, input().split())

    adj = [[] for _ in range(n)]

    eid = 0
    for _ in range(m):
        u, v, p = map(int, input().split())
        adj[u].append((v, p, eid))
        eid += 1

    removed = [False] * eid

    def dijkstra(build_parents=False):
        dist = [INF] * n
        dist[s] = 0
        parents = [[] for _ in range(n)] if build_parents else None
        h = [(0, s)]
        heappop = heapq.heappop
        heappush = heapq.heappush

        while h:
            cur_d, u = heappop(h)
            if cur_d > dist[u]:
                continue
            if u == d and not build_parents:
                return dist, parents
            for v, w, eidx in adj[u]:
                if removed[eidx]:
                    continue
                nd = cur_d + w
                if nd < dist[v]:
                    dist[v] = nd
                    if build_parents:
                        parents[v] = [(u, eidx)]
                    heappush(h, (nd, v))
                elif build_parents and nd == dist[v]:
                    parents[v].append((u, eidx))
        return dist, parents

    dist, parents = dijkstra(build_parents=True)

    q = deque()
    q.append(d)

    while q:
        v = q.popleft()
        for u, eidx in parents[v]:
            if not removed[eidx]:
                removed[eidx] = True
                q.append(u)

    dist2, _ = dijkstra(build_parents=False)
    ans = dist2[d]
    print(-1 if ans == INF else ans)
