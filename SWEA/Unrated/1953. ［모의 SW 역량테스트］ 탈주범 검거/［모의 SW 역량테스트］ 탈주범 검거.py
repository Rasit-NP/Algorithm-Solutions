from collections import deque

t = int(input())

for tc in range(1, t+1):
    n, m, r, c, l = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(n)]
    directions = {1: ((1, 0), (0, 1), (-1, 0), (0, -1)),
                 2: ((1, 0), (-1, 0)), 3: ((0, 1), (0, -1)),
                 4: ((0, 1), (-1, 0)), 5: ((1, 0), (0, 1)),
                 6: ((1, 0), (0, -1)), 7: ((-1, 0), (0, -1))}

    queue = deque([])
    visited = set()
    queue.append((r, c, 1))
    visited.add((r, c))

    while queue:
        x, y, time = queue.popleft()
        for dx, dy in directions[board[x][y]]:
            nx, ny = x+dx, y+dy
            if time < l and 0<=nx<n and 0<=ny<m and (nx, ny) not in visited and board[nx][ny] != 0 and (-dx, -dy) in directions[board[nx][ny]]:
                visited.add((nx, ny))
                queue.append((nx, ny, time+1))

    print(f'#{tc}', end=' ')
    print(len(visited))