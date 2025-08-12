import sys

n = int(sys.stdin.readline())
points = [None] * n

for i in range(n):
    x, y = map(float, sys.stdin.readline().split())
    points[i] = (x, y)

def area_tan(position1, position2):
    x1, y1 = position1
    x2, y2 = position2
    return abs(x2-x1) * (y1+y2)/2

def area_tri(position1, position2, position3):
    heap = []
    x1, y1 = position1
    x2, y2 = position2
    x3, y3 = position3
    vector1 = ((x1-x2),(y1-y2))
    vector2 = ((x1-x3),(y1-y3))

    return (vector1[0]*vector2[1] - vector1[1]*vector2[0])/2


origin = points[0]
area = 0
for i in range(1, n-1):
    point1 = points[i]
    point2 = points[i+1]
    area += area_tri(origin, point1, point2)

ans = str(abs(area)).split('.')
if len(ans[1])>1:
    if int(ans[1][1])>=5:
        ans[1] = str(int(ans[1][0] + 1))
    else:
        ans[1] = ans[1][0]
    print('.'.join(ans))
else:
    print('.'.join(ans))