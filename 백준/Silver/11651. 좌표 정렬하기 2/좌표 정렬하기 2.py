import sys, heapq

n = int(sys.stdin.readline())
heap = []

for _ in range(n):
    inputs = list(map(int, sys.stdin.readline().split()))

    heapq.heappush(heap,(inputs[1], inputs[0]))

for _ in range(n):
    position = heapq.heappop(heap)
    print(position[1], position[0])