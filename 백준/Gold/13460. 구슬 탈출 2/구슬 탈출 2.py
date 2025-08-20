import sys
from collections import deque


n, m = map(int, sys.stdin.readline().split())

board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j] == 'R':
            board[i][j] = '.'
            red = (i, j)
        elif board[i][j] == 'B':
            board[i][j] = '.'
            blue = (i, j)
        elif board[i][j] == 'O':
            exit = (i, j)

queue = deque([])
queue.append((0, red, blue))
visited = set()
visited.add((red, blue))

ans = -1

while queue:
    time, red, blue = queue.popleft()
    if time > 10:
        ans = -1
        queue.clear()
        break
    if red == exit:
        ans = time
        queue.clear()
        break
    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        xr, yr = red
        xb, yb = blue
        updated = True
        goal_red = 0
        goal_blue = 0
        while updated:
            updated = False
            nxr, nyr = xr+dx, yr+dy
            if goal_red == 0 and 0<=nxr<n and 0<=nyr<m:
                if board[nxr][nyr] == '.' and (nxr, nyr) != (xb, yb):
                    xr, yr = nxr, nyr
                    updated = True
                elif board[nxr][nyr] == 'O':
                    goal_red = 1
                    xr, yr = nxr, nyr
                    updated = True
            nxb, nyb = xb+dx, yb+dy
            if 0<=nxr<n and 0<=nyr<m:
                if board[nxb][nyb] == '.' and (goal_red or (nxb, nyb) != (xr, yr)):
                    xb, yb = nxb, nyb
                    updated = True
                elif board[nxb][nyb] == 'O':
                    goal_blue = 1
                    break
        if goal_blue:
            continue
        else:
            if ((xr, yr), (xb, yb)) not in visited:
                queue.append((time+1, (xr, yr), (xb, yb)))
                visited.add(((xr, yr), (xb, yb)))

print(ans)