import sys, heapq
from collections import deque

def detect(lvl, shark):
    x_shark, y_shark = shark
    queue = deque([])
    queue.append((0, x_shark, y_shark))
    visited = set()
    visited.add((x_shark, y_shark))
    heap = []
    shortest = float('inf')
    while queue:
        dist, x_now, y_now = queue.popleft()
        if dist > shortest:
            break
        elif 0 < dist <= shortest and 0 < board[x_now][y_now] < lvl:
            shortest = dist
            heapq.heappush(heap, (dist, x_now, y_now))
        else:
            for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                nx, ny = x_now+dx, y_now+dy
                if 0<=nx<n and 0<=ny<n:
                    if board[nx][ny] <= lvl and (nx, ny) not in visited:
                        queue.append((dist+1, nx, ny))
                        visited.add((nx, ny))
    if heap:
        target = heapq.heappop(heap)
        return target                   ## (거리, x좌표, y좌표)
    else:
        return (float('inf'), 0, 0)



n = int(sys.stdin.readline())
board = []

for i in range(n):
    inputs = list(map(int, sys.stdin.readline().split()))
    board.append(inputs)
    for j in range(n):
        if inputs[j] == 9:
            shark = (i, j)
            board[i][j] = 0


time = 0
lvl = 2
eat_count = 0

while True:
    dist_target, x_target, y_target = detect(lvl, shark)
    if dist_target == float('inf'):
        break
    
    time += dist_target
    shark = (x_target, y_target)
    eat_count += 1
    board[x_target][y_target] = 0

    if eat_count == lvl:
        eat_count = 0
        lvl += 1

print(time)