import sys, math

t = int(sys.stdin.readline())

for _ in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())
    d = math.sqrt((x1-x2)**2 + (y1-y2)**2)

    if d == 0 and r1 == r2:
        print(-1)
    elif 0 < d < abs(r1-r2) or d > (r1+r2) or d == 0:
        print(0)
    elif d == abs(r1-r2) or d == (r1+r2):
        print(1)
    elif abs(r1-r2) < d < (r1+r2):
        print(2)