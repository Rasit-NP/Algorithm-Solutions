import sys, heapq

n = int(sys.stdin.readline())
meetings = []

first = float('inf')
last = 0
for _ in range(n):
    s, e = map(int, sys.stdin.readline().split())
    heapq.heappush(meetings, (s, e))
    first = min(first, s)
    last = max(last, e)

ans = [0]*(last+1)
latest = first
start, end = heapq.heappop(meetings)
for i in range(first, last+1):
    while i == start:
        if ans[end] < ans[start] + 1:
            ans[end] = ans[start] + 1
        if len(meetings) > 0:
            start, end = heapq.heappop(meetings)
        else:
            start = float('inf')
    if i != start and i < last:
        if ans[i+1] < ans[i]:
            ans[i+1] = ans[i]


print(ans[-1])