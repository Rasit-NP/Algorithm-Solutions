import sys
from collections import deque

def bfs(queue):
    a = queue.popleft()
    x = a[0]
    y = a[1]
    distance = a[2]
    breaked = a[3]
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    if x == n-1 and y == m-1:
        print(distance)
        queue.clear()
        return
    else:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<m:
                if breaked == 1:
                    if maze[nx][ny] == 0 and (nx,ny,1) not in visited:  #이미 부숴서 못 부숨
                        visited.add((nx,ny,breaked))
                        queue.append([nx, ny, distance+1, breaked])
                else:
                    if maze[nx][ny] == 0 and (nx,ny,0) not in visited:  #아직 안부쉈는데 벽 아님
                        visited.add((nx,ny,breaked))
                        queue.append([nx, ny, distance+1, breaked])
                    elif maze[nx][ny] == 1 and (nx,ny,1) not in visited: #아직 안부쉈는데 이제 부숨
                        visited.add((nx,ny,1))
                        queue.append([nx, ny, distance+1, 1])
            else:
                continue


n, m = map(int,sys.stdin.readline().split())
maze = []
visited = set()
visited.add((0,0,0))      # [x,y,부순 횟수]
queue = deque([])
queue.append([0,0,1,0])     # [x,y,거리,부순 횟수]

for _ in range(n):
    inputs = list(sys.stdin.readline().rstrip())
    maze.append(list(map(int,inputs)))

while queue:
    bfs(queue)

if (n-1,m-1,1) not in visited and (n-1,m-1,0) not in visited:
    print(-1)