# BOJ 8972
import sys

def input():
    r, c = map(int, sys.stdin.readline().split())

    board = [list(sys.stdin.readline().rstrip()) for _ in range(r)]
    crazy = set()
    for i in range(r):
        for j in range(c):
            if board[i][j] == 'I':
                position = (i, j)
            elif board[i][j] == 'R':
                crazy.add((i, j))
    moves = list(map(int, sys.stdin.readline().rstrip()))

    return r, c, position, board, crazy, moves

direction = {1:(1, -1), 2:(1, 0), 3:(1, 1), 4:(0, -1),
             5:(0, 0), 6:(0, 1), 7:(-1, -1), 8:(-1, 0), 9:(-1, 1)}

r, c, position, board, crazys, moves = input()

ans = 0
for i in range(len(moves)):
    if ans:
        break
    x, y = position
    dx, dy = direction[moves[i]]
    nx, ny = x+dx, y+dy
    if (nx, ny) in crazys:
        ans = i+1
        break
    new_set = set()
    explode = set()
    for cx, cy in crazys:
        minimum = float('inf')
        for k in range(1, 10):
            dcx, dcy = direction[k]
            dist = abs(cx+dcx-nx)+abs(cy+dcy-ny)
            if dist < minimum:
                minimum = dist
                new_dir = (dcx, dcy)
        ncx, ncy = cx+new_dir[0], cy+new_dir[1]
        if nx==ncx and ny==ncy:
            ans = i+1
            break
        if (ncx, ncy) not in new_set|explode:
            new_set.add((ncx,ncy))
        elif (ncx, ncy) in new_set:
            new_set.remove((ncx,ncy))
            explode.add((ncx,ncy))
        elif (ncx, ncy) in explode:
            continue
    position = (nx, ny)
    crazys = new_set

if ans:
    print(f'kraj {ans}')
else:
    board = [['.' for _ in range(c)] for _ in range(r)]
    x, y = position
    board[x][y] = 'I'
    for cx, cy in crazys:
        board[cx][cy] = 'R'
    for i in range(r):
        print(''.join(board[i]))