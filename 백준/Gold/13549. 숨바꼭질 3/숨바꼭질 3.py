import sys, heapq

n, k = map(int, sys.stdin.readline().split())

heap = []
heap.append((0,n))
visited = [float('inf')] * 100001
visited[n] = 0
count = 0

while heap:
    time, position = heapq.heappop(heap)
    nxs = [position+1, position-1]

    if position == k:
        heap.clear()
        break

    for nx in nxs:
        if 0<=nx<=100000 and time+1 < visited[nx]:
            visited[nx] = time+1
            heapq.heappush(heap,(time+1, nx))
    if 0<=2*position<=100000 and time < visited[2*position] and position < k:
        visited[2*position] = time
        heapq.heappush(heap, (time, 2*position))

print(time)