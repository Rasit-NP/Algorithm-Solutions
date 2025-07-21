import sys
from collections import deque

def bfs(lis, queue):
    x, y, z, t = queue[0]
    dx = [1, -1, 0, 0, 0, 0]
    dy = [0, 0, 1, -1, 0, 0]
    dz = [0, 0, 0, 0, 1, -1]
    a = queue.popleft()
    for i in range(6):
        nx = x + dx[i]
        ny = y + dy[i]
        nz = z + dz[i]
        nt = t + 1
        if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h and lis[nz][ny][nx] == 0:
            lis[nz][ny][nx] = nt
            queue.append([nx,ny,nz,nt])
    global ans
    ans = a[3]

m, n, h = map(int, sys.stdin.readline().split())
tom = [[[0]*m for _ in range(n)] for _ in range(h)]
queue = deque([])

for i in range(h):
    for j in range(n):
        input = list(map(int, sys.stdin.readline().split()))
        for k in range(m):
            tom[i][j][k] = input[k]
            if tom[i][j][k] == 1:
                queue.append([k, j, i, 0])

while len(queue)>0:
    bfs(tom, queue)

for i in range(h):
    for j in range(n):
        for k in range(m):
            if tom[i][j][k] == 0:
                ans = -1
                break

print(ans)