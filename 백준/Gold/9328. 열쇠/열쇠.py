import sys
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t):
    h, w = map(int, sys.stdin.readline().split())

    board = [['.'] * (w+2)]
    for _ in range(h):
        board.append(['.']+list(sys.stdin.readline().rstrip())+['.'])
    board.append(['.']*(w+2))

    keys = list(sys.stdin.readline().rstrip())
    
    door = {'A':'a', 'B':'b', 'C':'c', 'D':'d', 'E':'e', 'F':'f', 'G':'g', 'H':'h', 'I':'i',
            'J':'j', 'K':'k', 'L':'l', 'M':'m', 'N':'n', 'O':'o', 'P':'p', 'Q':'q', 'R':'r',
            'S':'s', 'T':'t', 'U':'u', 'V':'v', 'W':'w', 'X':'x', 'Y':'y', 'Z':'z'}

    count = 0

    while True:
        queue = deque([])
        visited = set()
        queue.append((0, 0))
        visited.add((0, 0))

        updated = False

        while queue:
            x, y = queue.popleft()
            for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                nx, ny = x+dx, y+dy
                if 0<=nx<h+2 and 0<=ny<w+2 and board[nx][ny] != '*' and (nx, ny) not in visited:
                    data = board[nx][ny]
                    if data == '.':
                        queue.append((nx, ny))
                        visited.add((nx, ny))
                    elif data == '$':
                        queue.append((nx, ny))
                        visited.add((nx, ny))
                        board[nx][ny] = '.'
                        count += 1
                        updated = True
                    else:
                        if data in door.values():
                            queue.append((nx, ny))
                            visited.add((nx, ny))
                            keys.append(data)
                            board[nx][ny] = '.'
                            updated = True
                        else:
                            if door[data] in keys:
                                queue.append((nx, ny))
                                visited.add((nx, ny))
                                board[nx][ny] = '.'
                                updated = True
        if updated:
            continue
        else:
            break
    
    print(count)