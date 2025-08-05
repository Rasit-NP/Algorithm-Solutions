import heapq, copy
from pprint import pprint

t = int(input())

for tc in range(1, t+1):
    n, w, h = map(int, input().split())
    board = [[None]*h for _ in range(w)]        #board[w][h]
    highest = [None] * w
    blocks = 0

    for i in range(h):
        inputs = list(map(int, input().split()))
        for j in range(len(inputs)):
            board[j][i] = inputs[j]
            if inputs[j] != 0:
                blocks += 1
                if highest[j] == None:
                    highest[j] = i

    def oneShot(x, board, highest):
        yets = []
        breaked = []

        if board[x][highest[x]] == 1:
            heapq.heappush(breaked,(x,highest[x]))
        elif board[x][highest[x]] != 0:
            yets.append((x,highest[x]))
            heapq.heappush(breaked,(x,highest[x]))

        while len(yets)>0:
            now_x, now_y = yets.pop()
            scale = board[now_x][now_y] - 1
            dx = [1, -1, 0, 0]
            dy = [0, 0, 1, -1]
            
            for dist in range(1, scale+1):
                for i in range(4):
                    nx = now_x + dx[i]*dist
                    ny = now_y + dy[i]*dist
                    if 0<=nx<w and 0<=ny<h and board[nx][ny] > 0 and (nx, ny) not in breaked and (nx, ny) not in yets:
                        heapq.heappush(breaked,(nx,ny))
                        if board[nx][ny] != 1:
                            yets.append((nx,ny))
        count_break = len(breaked)
        while breaked:
            breaked_x, breaked_y = heapq.heappop(breaked)
            board[breaked_x].pop(breaked_y)
            board[breaked_x] = [0]+board[breaked_x]

        for i in range(w):
            highest[i] = board[i].count(0)
            if highest[i] == h:
                highest[i] = None

        return board, count_break, highest

    lst = []
    maximum = 0
    def perm(lst, highest):
        global maximum
        if len(lst) == n:
            test_board = copy.deepcopy(board)
            test_highest = copy.deepcopy(highest)
            count_break = 0

            for i in range(n):
                x = lst[i]
                if count_break == blocks:
                    return 0
                if test_highest[x] == None:
                    break
                result = oneShot(x, test_board, test_highest)
                test_board = result[0]
                count_break += result[1]
                test_highest = result[2]
            maximum = max(maximum, count_break)

        else:
            for i in range(w):
                lst.append(i)
                if perm(lst, highest) == 0:
                    return 0
                lst.pop()
    
    a = perm(lst, highest)

    if a == 0:
        print(f'#{tc}', a)
    else:
        print(f'#{tc}', blocks - maximum)