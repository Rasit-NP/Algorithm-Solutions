import sys, heapq

n = int(sys.stdin.readline())
heap = []
for _ in range(n):
    order = int(sys.stdin.readline())
    if order == 0:
        if len(heap)==0:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap,order)