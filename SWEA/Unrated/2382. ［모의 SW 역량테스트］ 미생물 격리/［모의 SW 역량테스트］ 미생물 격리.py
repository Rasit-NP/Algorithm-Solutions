import heapq
from pprint import pprint
t = int(input())

for tc in range(1, t+1):
    n, m, k = map(int, input().split())
    germs = {}
    directions = [None, (-1,0), (1,0), (0,-1), (0,1)]
    for _ in range(k):
        x, y, cells, direction = map(int, input().split())
        germs[(x,y)] = [(cells, direction)]
    
    def time_is_going(germs):
        next_germs = {}
        for positions in germs:
            x, y = positions
            cells = abs(germs[(x,y)][0][0])
            direction = germs[(x,y)][0][1]
            nx, ny = x + directions[direction][0], y + directions[direction][1]
            if nx == 0 or nx == n-1 or ny == 0 or ny == n-1:
                if direction == 1:
                    direction = 2
                elif direction == 2:
                    direction = 1
                elif direction == 3:
                    direction = 4
                elif direction == 4:
                    direction = 3
                cells = cells//2
                if (nx,ny) not in next_germs:
                    next_germs[(nx,ny)] = [(-cells, direction)]
                else:
                    heapq.heappush(next_germs[(nx,ny)], (-cells, direction))
            else:
                if (nx,ny) not in next_germs:
                    next_germs[(nx,ny)] = [(-cells, direction)]
                else:
                    heapq.heappush(next_germs[(nx,ny)], (-cells, direction))
        for positions in next_germs:
            counts = len(next_germs[positions])
            if counts > 1:
                maximum = 0
                total = 0
                for i in range(counts):
                    cell = abs(next_germs[positions][i][0])
                    if cell > maximum:
                        maximum = cell
                        max_idx = i
                    total += cell
                direction = next_germs[positions][max_idx][1]
                next_germs[positions] = [(-total, direction)]
        return next_germs

    for _ in range(m):
        germs = time_is_going(germs)

    total = 0
    for key in germs:
        total += abs(germs[key][0][0])
    print(f'#{tc}', total)