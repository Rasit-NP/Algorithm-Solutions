import sys, heapq

n = int(sys.stdin.readline())
heap = []
for _ in range(n):
    s, t = map(int, sys.stdin.readline().split())
    heap.append((s, 1))
    heap.append((t, -1))
heapq.heapify(heap)
cnt = 0; maximum = 0
for i in range(2*n):
    x, i = heapq.heappop(heap)
    cnt += i
    maximum = max(maximum, cnt)

print(maximum)