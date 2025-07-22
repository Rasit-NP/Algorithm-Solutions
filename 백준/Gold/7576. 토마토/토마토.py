import sys
from collections import deque

def bfs(lis, queue):
    a = queue.popleft()
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    global stat
    stat = a[2]
    for i in range(4):
        nx = a[0] + dx[i]
        ny = a[1] + dy[i]
        if 0 <= nx < m and 0 <= ny < n and lis[ny][nx] == 0:
            queue.append([nx,ny,a[2]+1])
            lis[ny][nx] = a[2] + 1
    

m, n = map(int, sys.stdin.readline().split())
tom = [[0]*m for _ in range(n)]
queue = deque([])

for i in range(n):
    input = sys.stdin.readline().split()
    for j in range(m):
        tom[i][j] = int(input[j])
        if tom[i][j] == 1:
            queue.append([j,i,0])

while queue:
    bfs(tom, queue)

for i in range(m):
    for j in range(n):
        if tom[j][i] == 0:
            stat = -1

print(stat)