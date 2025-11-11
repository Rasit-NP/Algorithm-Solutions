import sys, heapq

n = int(sys.stdin.readline())
heap = []

for _ in range(n):
    x = int(sys.stdin.readline())
    heapq.heappush(heap, x)

ans = 0

while n > 1:
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    heapq.heappush(heap, a+b)
    ans += a+b
    n -= 1

print(ans)