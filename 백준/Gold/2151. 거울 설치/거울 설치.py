import sys, heapq

n = int(sys.stdin.readline())

board = []
doors = []
visited = {}
for i in range(n):
    inputs = list(sys.stdin.readline().rstrip())
    board.append(inputs)
    for j in range(n):
        if inputs[j] == '#':
            doors.append((i, j))

for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
    visited[(dx, dy)] = [[float('inf')]*n for _ in range(n)]

start, exit = doors

for key in visited:
    visited[key][start[0]][start[1]] = 0

heap = []
for dx, dy in visited:
    x, y = start
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<n and board[nx][ny] != '*':
        if board[nx][ny] == '!':
            for new_dx, new_dy in visited:
                dot = dx*new_dx + dy*new_dy
                if dot == 0:
                    heapq.heappush(heap, (1, (new_dx, new_dy), (nx, ny)))
                    visited[(new_dx, new_dy)][nx][ny] = 1
        heapq.heappush(heap,(0, (dx, dy), (nx, ny)))
        visited[(dx, dy)][nx][ny] = 0

while heap:
    count, (dx, dy), (x, y) = heapq.heappop(heap)
    if (x, y) == exit:
        print(count)
        heap.clear()
        break
    
    nx, ny = x+dx, y+dy
    if 0<=nx<n and 0<=ny<n and board[nx][ny] != '*':
        if board[nx][ny] == '!':
            for new_dx, new_dy in visited:
                dot = dx*new_dx + dy*new_dy
                if dot == 0 and visited[(new_dx, new_dy)][nx][ny] > count+1:
                    heapq.heappush(heap, (count+1, (new_dx, new_dy), (nx, ny)))
                    visited[(new_dx, new_dy)][nx][ny] = count+1
        if visited[(dx, dy)][nx][ny] > count:
            heapq.heappush(heap, (count, (dx, dy), (nx, ny)))
            visited[(dx, dy)][nx][ny] = count