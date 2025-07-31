import heapq

t = int(input())

for testcase in range(1, t+1):
    n = int(input())
    board = []
    heap = [(0,[0,0])]          # (time, [x, y])
    visited = [[float('inf')]*n for _ in range(n)]
    visited[0][0] = 0
    
    for _ in range(n):
        board.append(list(map(int,list(input()))))

    while heap:
        now = heapq.heappop(heap)
        spenttime = now[0]
        x = now[1][0]
        y = now[1][1]
        if x==n-1 and y == n-1:
            print(f'#{testcase} {spenttime}')
            heap.clear()
            break
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<n and 0<=ny<n and visited[nx][ny] > now[0] + board[nx][ny]:
                visited[nx][ny] = now[0] + board[nx][ny]
                heapq.heappush(heap,(visited[nx][ny],[nx,ny]))