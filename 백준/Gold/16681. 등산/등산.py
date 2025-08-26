import sys, heapq

def input():
    N, m, d, e = map(int, sys.stdin.readline().split())
    h = [0] + list(map(int, sys.stdin.readline().split()))
    edges = [[] for _ in range(N+1)]
    for _ in range(m):
        a, b, n = map(int, sys.stdin.readline().split())
        edges[a].append((b, n*d))
        edges[b].append((a, n*d))

    return N, m, d, e, h, edges

n, m, d, e, h, edges = input()

heap1 = []
heap1.append((-e, 1))
first = [float('inf')] * (n+1)
first[1] = -e

while heap1:
    score, position = heapq.heappop(heap1)
    h_now = h[position]
    for next, dist in edges[position]:
        h_new = h[next]
        if h_new > h_now and first[next] > score - (h_new-h_now)*e + dist:
            first[next] = score - (h_new-h_now)*e + dist
            heapq.heappush(heap1, (first[next], next))

heap2 = []
second = [float('inf')] * (n+1)

for i in range(2, n):
    if first[i] < float('inf'):
        heapq.heappush(heap2, (first[i], i))
        second[i] = first[i]

ans = 'Impossible'
while heap2:
    score, position = heapq.heappop(heap2)
    if position == n:
        ans = -score
        heap2.clear()
        break
    for next, dist in edges[position]:
        if h[next] < h[position] and second[next] > score + dist:
            second[next] = score + dist
            heapq.heappush(heap2, (second[next], next))
print(ans)