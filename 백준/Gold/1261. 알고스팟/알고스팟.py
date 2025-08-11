import sys, heapq

m, n = map(int, sys.stdin.readline().split())

board = [None] * n
for i in range(n):
    board[i] = list(map(int, list(sys.stdin.readline().rstrip())))

visited = set()
heap = []
heapq.heappush(heap,(0, (0, 0)))
visited.add((0, (0, 0)))
memo = [[None]*m for _ in range(n)]

while heap:
    count, position = heapq.heappop(heap)
    x, y = position
    if (x, y) == (n-1, m-1):
        print(count)
        heap.clear()

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<m:
            if board[nx][ny] == 1 and (memo[nx][ny] == None or count+1 < memo[nx][ny]):
                heapq.heappush(heap,(count+1, (nx,ny)))
                memo[nx][ny] = count+1
            
            elif board[nx][ny] == 0 and (memo[nx][ny] == None or count < memo[nx][ny]):
                heapq.heappush(heap, (count, (nx,ny)))
                memo[nx][ny] = count