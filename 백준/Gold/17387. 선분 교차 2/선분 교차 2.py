import sys

def line1(x, y):
    global x1, y1, x2, y2
    judge = (y-y1)*(x2-x1) - (x-x1)*(y2-y1)
    if judge > 0:
        return 1
    elif judge == 0:
        return 0
    elif judge < 0:
        return -1

def line2(x, y):
    global x3, y3, x4, y4
    judge = (y-y3)*(x4-x3) - (x-x3)*(y4-y3)
    if judge > 0:
        return 1
    elif judge == 0:
        return 0
    elif judge < 0:
        return -1

x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
x3, y3, x4, y4 = map(int, sys.stdin.readline().split())

judge1 = line1(x3, y3) * line1(x4, y4)
judge2 = line2(x1, y1) * line2(x2, y2)

if judge1 <= 0 and judge2 <= 0:
    if (x1 > max(x3, x4) and x2 > max(x3, x4)) or (y1 > max(y3, y4) and y2 > max(y3, y4)) or (x1 < min(x3, x4) and x2 < min(x3, x4)) or (y1 < min(y3, y4) and y2 < min(y3, y4)):
        print(0)
    else:
        print(1)
else:
    print(0)