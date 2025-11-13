import sys, heapq

input = sys.stdin.readline

n, k = map(int, input().split())
heap = []

for _ in range(n):
    m, v = map(int, input().split())
    heap.append((m, v))
for _ in range(k):
    c = int(input())
    heap.append((c, 1000001))
heapq.heapify(heap)
cnt = 0
ans = 0
jems = []
while (cnt<k and heap):
    m, v = heapq.heappop(heap)
    if v<=1000000:
        heapq.heappush(jems, (-v))
    else:
        cnt += 1
        if jems:
            v = -heapq.heappop(jems)
            ans += v
print(ans)