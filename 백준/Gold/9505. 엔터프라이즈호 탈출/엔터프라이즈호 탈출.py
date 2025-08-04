import sys, heapq

n = int(sys.stdin.readline())

for _ in range(n):
    k, w, h = map(int, sys.stdin.readline().split())
    flight = {}
    board = []
    visited = [[float('inf')]* w for _ in range(h)]
    for _ in range(k):
        name, numbers = sys.stdin.readline().split()
        flight[name] = int(numbers)
    for i in range(h):
        inputs = list(sys.stdin.readline().rstrip())
        board.append(inputs)
        if 'E' in inputs:
            position = (i, inputs.index('E'))
            visited[i][inputs.index('E')] = 0
            heap = [(0, position)]

    while heap:
        spent_time, now_position = heapq.heappop(heap)
        if now_position == (h, w):
            print(spent_time)
            heap.clear()
            break
        x, y = now_position
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx<0 or ny<0 or nx==h or ny == w:
                heapq.heappush(heap, (spent_time, (h, w)))
            elif board[nx][ny] != 'E' and visited[nx][ny] > spent_time + flight[board[nx][ny]]:
                visited[nx][ny] = spent_time + flight[board[nx][ny]]
                heapq.heappush(heap,(visited[nx][ny], (nx, ny)))