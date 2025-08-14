from pprint import pprint
import sys, heapq

w, h = map(int, sys.stdin.readline().split())

board = [None] * h
points = []

for i in range(h):
    inputs = list(sys.stdin.readline().rstrip())
    board[i] = inputs
    for j in range(w):
        if inputs[j] == 'C' or inputs[j] == 'c':
            points.append((i, j))
start = points[0]

heap = []
visited = {}
for dx, dy in ((1,0),(0,1),(-1,0),(0,-1)):
    visited[(dx,dy)] = [[float('inf')]*w for _ in range(h)]
    nx, ny = start[0]+dx, start[1]+dy
    visited[(dx,dy)][start[0]][start[1]] = 0
    if 0<=nx<h and 0<=ny<w and board[nx][ny] != '*':
        heapq.heappush(heap, (0, (dx, dy), (nx, ny)))
        visited[(dx,dy)][nx][ny] = 0

ans = 0
while heap:
    count, (dx_origin, dy_origin), (x, y) = heapq.heappop(heap)
    if visited[(dx,dy)][x][y] < count:
        continue
    if board[x][y] == 'C' or board[x][y] == 'c':
        ans = count
        heap.clear()
        break
    for dx, dy in ((1,0),(0,1),(-1,0),(0,-1)):
        nx, ny = x+dx, y+dy
        dot = dx*dx_origin + dy*dy_origin
        if 0<=nx<h and 0<=ny<w and board[nx][ny] != '*':
            if dot == 1 and visited[(dx,dy)][nx][ny] > count:
                heapq.heappush(heap, (count, (dx, dy), (nx, ny)))
                visited[(dx,dy)][nx][ny] = count
            elif dot == 0 and visited[(dx,dy)][nx][ny] > count+1:
                heapq.heappush(heap, (count+1, (dx, dy), (nx, ny)))
                visited[(dx,dy)][nx][ny] = count+1
            elif dot == -1:
                continue

print(ans)