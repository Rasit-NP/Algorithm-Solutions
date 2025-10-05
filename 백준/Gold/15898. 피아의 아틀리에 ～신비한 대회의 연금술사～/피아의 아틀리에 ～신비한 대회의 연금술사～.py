import sys
from itertools import permutations

def init(n):
    global qualities, colors, pos

    qualities = []
    colors = []
    pos = ((0, 0), (1, 0), (0, 1), (1, 1))
    for _ in range(n):
        q0 = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
        c0 = [list(sys.stdin.readline().rstrip().split()) for _ in range(4)]
        q1 = rot(q0)
        q2 = rot(q1)
        q3 = rot(q2)
        qualities.append((q0, q1, q2, q3))
        c1 = rot(c0)
        c2 = rot(c1)
        c3 = rot(c2)
        colors.append((c0, c1, c2, c3))

def rot(matrix):
    return [[matrix[3-j][i] for j in range(4)] for i in range(4)]

def cal(orders, order_rot, order_pos):
    board_q = [[0 for _ in range(5)] for _ in range(5)]
    board_c = [["W" for _ in range(5)] for _ in range(5)]
    total = 0

    for i in range(3):
        mat_q = qualities[orders[i]][order_rot[i]]
        mat_c = colors[orders[i]][order_rot[i]]
        x, y = pos[order_pos[i]]
        for dx in range(4):
            for dy in range(4):
                nx, ny = x+dx, y+dy
                board_q[nx][ny] += mat_q[dx][dy]
                if board_q[nx][ny] > 9:     board_q[nx][ny] = 9
                elif board_q[nx][ny] <0:    board_q[nx][ny] = 0
                if mat_c[dx][dy] != 'W':
                    board_c[nx][ny] = mat_c[dx][dy]
    for i in range(5):
        for j in range(5):
            color = board_c[i][j]
            if color == 'R':
                total += 7 * board_q[i][j]
            elif color == 'B':
                total += 5 * board_q[i][j]
            elif color == 'G':
                total += 3 * board_q[i][j]
            elif color == 'Y':
                total += 2 * board_q[i][j]
    return total

if __name__=="__main__":
    n = int(sys.stdin.readline())
    init(n)
    orders_rot = []
    orders_pos = []
    for i in range(4):
        for j in range(4):
            for k in range(4):
                orders_rot.append((i, j, k))
                if i == 0:
                    orders_pos.append((i, j, k))
    maximum = 0
    for orders in permutations(range(n), 3):
        for order_rot in orders_rot:
            for order_pos in orders_pos:
                score = cal(orders, order_rot, order_pos)
                if score > maximum:
                    maximum = score
    print(maximum)