import sys
from collections import deque

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

apples = []

for _ in range(k):
    apple_x, apple_y = map(int, sys.stdin.readline().split())
    apples.append((apple_x-1, apple_y-1))
apples = set(apples)
l = int(sys.stdin.readline())

directions = []
for _ in range(l):
    time, d = sys.stdin.readline().rstrip().split()
    directions.append((int(time), d))


x, y = 0, 0
body = deque([])
body.append((x,y))
direction = (0, 1)
time = 0
while True:
    time += 1
    x, y = body[-1]
    dx, dy = direction
    nx, ny = x + dx, y + dy

    if (nx,ny) in set(body) or nx == -1 or ny == -1 or nx == n or ny == n:
        break
    elif (nx,ny) in apples:
        body.append((nx,ny))
        apples.remove((nx,ny))
    else:
        body.append((nx,ny))
        body.popleft()
    
    if len(directions)>0:
        change_time, change_direction = directions[0]
        if time == change_time:
            if change_direction == 'L':
                direction = (-dy, dx)
            elif change_direction == 'D':
                direction = (dy, -dx)
            directions = directions[1:]

print(time)