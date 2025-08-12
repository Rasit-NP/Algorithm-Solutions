import sys, heapq

n, m = map(int, sys.stdin.readline().split())
board = [None]*n

for i in range(n):
    inputs = list(sys.stdin.readline().rstrip())
    board[i] = inputs
    for j in range(m):
        if inputs[j] == 'S':
            start = (i,j)
        elif inputs[j] == 'F':
            finish = (i,j)
for i in range(n):
    for j in range(m):
        if board[i][j] == 'g':
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni = i + di
                nj = j + dj
                if 0<=ni<n and 0<=nj<m and board[ni][nj] == '.':
                    board[ni][nj] = 'x'
                    

visited = [[[float('inf')]* 2 for _ in range(m)] for _ in range(n)]
visited[start[0]][start[1]] = (0, 0)    # 쓰밟, 쓰옆
heap = [(0, 0, start)]                  # 쓰밟, 쓰옆, (위치)

while heap:
    trash, garbage, (x, y) = heapq.heappop(heap)
    if (x, y) == finish:
        ans = (trash, garbage)
        heap.clear()
        break
    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        nx = x + dx
        ny = y + dy
        if 0<=nx<n and 0<=ny<m:
            if board[nx][ny] == 'g':
                new_trash = trash + 1
                new_garbage = garbage
                if visited[nx][ny][0] > new_trash:
                    visited[nx][ny][0] = new_trash
                    visited[nx][ny][1] = new_garbage
                    heapq.heappush(heap,(new_trash, new_garbage, (nx,ny)))
                elif visited[nx][ny][0] == new_trash and visited[nx][ny][1] > new_garbage:
                    visited[nx][ny][1] = new_garbage
                    heapq.heappush(heap,(new_trash, new_garbage, (nx,ny)))
            elif board[nx][ny] == 'x':
                new_trash = trash
                new_garbage = garbage + 1
                if visited[nx][ny][0] > new_trash:
                    visited[nx][ny][0] = new_trash
                    visited[nx][ny][1] = new_garbage
                    heapq.heappush(heap,(new_trash, new_garbage, (nx,ny)))
                elif visited[nx][ny][0] == new_trash and visited[nx][ny][1] > new_garbage:
                    visited[nx][ny][1] = new_garbage
                    heapq.heappush(heap,(new_trash, new_garbage, (nx,ny)))
            else:
                new_trash = trash
                new_garbage = garbage
                if visited[nx][ny][0] > new_trash:
                    visited[nx][ny][0] = new_trash
                    visited[nx][ny][1] = new_garbage
                    heapq.heappush(heap,(new_trash, new_garbage, (nx,ny)))
                elif visited[nx][ny][0] == new_trash and visited[nx][ny][1] > new_garbage:
                    visited[nx][ny][1] = new_garbage
                    heapq.heappush(heap,(new_trash, new_garbage, (nx,ny)))

print(ans[0], ans[1])