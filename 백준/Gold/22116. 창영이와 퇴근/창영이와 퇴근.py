import sys, heapq

def input():
    n = int(sys.stdin.readline())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    visited = [[float('inf') for _ in range(n)] for _ in range(n)]

    return n, board, visited

n, board, visited = input()

heap = []
visited[0][0] = 0
heapq.heappush(heap, (0, (0, 0)))

while heap:
    maximum, position = heapq.heappop(heap)
    x, y = position
    if x == n-1 and y == n-1:
        ans = maximum
        heap.clear()
        break
    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        nx, ny = x+dx, y+dy
        if 0<=nx<n and 0<=ny<n:
            if visited[nx][ny] > max(maximum, abs(board[nx][ny]-board[x][y])):
                visited[nx][ny] = max(maximum, abs(board[nx][ny]-board[x][y]))
                heapq.heappush(heap,(visited[nx][ny], (nx, ny)))

print(ans)