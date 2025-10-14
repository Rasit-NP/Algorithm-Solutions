import sys

def init(n):
    global squares, parents, origin
    origin = False
    squares = []
    parents = [i for i in range(n)]
    for i in range(n):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        if check_meet((0, 0, 0, 0), (x1, y1, x2, y2)):
            origin = True
        for j in range(i):
            meet = check_meet((x1, y1, x2, y2), squares[j])
            if meet:
                r1, r2 = find(i), find(j)
                if find(i) != find(j):
                    parents[r2] = r1
        squares.append((x1, y1, x2, y2))

    return

def check_meet(square1, square2):
    x11, y11, x12, y12 = square1
    x21, y21, x22, y22 = square2
    min_x_1 = min(x11, x12);    max_x_1 = max(x11, x12)
    min_y_1 = min(y11, y12);    max_y_1 = max(y11, y12)
    min_x_2 = min(x21, x22);    max_x_2 = max(x21, x22)
    min_y_2 = min(y21, y22);    max_y_2 = max(y21, y22)
    if min_x_1 < min_x_2 and max_x_1 > max_x_2 and min_y_1 < min_y_2 and max_y_1 > max_y_2:
        return False
    if min_x_1 > min_x_2 and max_x_1 < max_x_2 and min_y_1 > min_y_2 and max_y_1 < max_y_2:
        return False
    if max_x_1 < min_x_2 or max_y_1 < min_y_2 or max_x_2 < min_x_1 or max_y_2 < min_y_1:
        return False
    else:
        return True

def find(x):
    root = x
    while root != parents[root]:
        parents[root] = parents[parents[root]]
        root = parents[root]
    parents[x] = root

    return root

def count():
    for i in range(n):
        find(i)
    ans = set(parents)
    if origin:
        print(len(ans)-1)
    else:
        print(len(ans))
    return

if __name__=='__main__':
    n = int(sys.stdin.readline())
    init(n)
    count()