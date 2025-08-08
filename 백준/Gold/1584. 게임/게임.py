import sys, heapq

def is_danger(position, danger_lst):
    x, y = position
    for x1, y1, x2, y2 in danger_lst:
        if min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
            return True
    return False

def is_death(position, death_lst):
    x, y = position
    for x1, y1, x2, y2 in death_lst:
        if min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
            return True
    return False

n = int(sys.stdin.readline())
danger = [None] * n
for i in range(n):
    danger[i] = tuple(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())
death = [None] * m
for i in range(m):
    death[i] = tuple(map(int, sys.stdin.readline().split()))

visited = [[float('inf')]*501 for _ in range(501)]
visited[0][0] = 0
heap = []
heap.append((0,(0,0)))

while heap:
    lost_life, posi = heapq.heappop(heap)
    x, y = posi
    if x == 500 and y == 500:
        print(lost_life)
        heap.clear()
        break
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<=500 and 0<=ny<=500:
            if is_death((nx,ny), death):
                continue
            elif is_danger((nx,ny), danger):
                if visited[nx][ny] > lost_life + 1:
                    visited[nx][ny] = lost_life + 1
                    heapq.heappush(heap,(visited[nx][ny],(nx,ny)))
            else:
                if visited[nx][ny] > lost_life:
                    visited[nx][ny] = lost_life
                    heapq.heappush(heap,(visited[nx][ny],(nx,ny)))

if visited[500][500] == float('inf'):
    print(-1)
