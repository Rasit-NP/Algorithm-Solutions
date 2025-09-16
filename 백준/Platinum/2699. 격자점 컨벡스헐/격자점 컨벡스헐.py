import sys
from decimal import Decimal, ROUND_HALF_UP

def input(n):
    global points, start

    points = []
    max_y = -float('inf')
    for _ in range(n//5):
        inputs = list(map(int, sys.stdin.readline().split()))
        for i in range(0, 10, 2):
            x, y = inputs[i], inputs[i+1]
            points.append((x, y))
            if y > max_y:
                max_y = y
                start = (x, y)
            elif y == max_y:
                if x < start[0]:
                    start = (x, y)
    
    if n%5:
        inputs = list(map(int, sys.stdin.readline().split()))
        for i in range(0, 2*(n%5), 2):
            x, y = inputs[i], inputs[i+1]
            points.append((x, y))
            if y > max_y:
                max_y = y
                start = (x, y)
            elif y == max_y:
                if x < start[0]:
                    start = (x, y)

    return

def run(points, start):
    def find_cosine(vec1, vec2):
        x1, y1 = vec1
        x2, y2 = vec2
        dot = Decimal(str((x1*x2 + y1*y2)))
        len1 = Decimal.sqrt(Decimal(str((x1**2+y1**2))))
        len2 = Decimal.sqrt(Decimal(str((x2**2+y2**2))))
        return dot/(len1*len2)

    def dist_square(pos1, pos2):
        x1, y1 = pos1
        x2, y2 = pos2
        return (x1-x2)**2 + (y1-y2)**2
    
    global lst

    lst = []
    sets = set()
    position_now = start
    vector_now = (1, 0)
    while position_now not in sets:
        cosine_max = Decimal(-2)
        lst.append(position_now)
        sets.add(position_now)
        for point in points:
            if point == position_now:
                continue
            vector_p = (point[0]-position_now[0], point[1]-position_now[1])
            cosine_p = find_cosine(vector_now, vector_p).quantize(Decimal('0.000001'), rounding=ROUND_HALF_UP)
            if cosine_p > cosine_max:
                cosine_max = cosine_p
                position_next = point
            elif cosine_p == cosine_max:
                if dist_square(position_now, point) > dist_square(position_now, position_next):
                    position_next = point
        vector_now = (position_next[0]-position_now[0], position_next[1]-position_now[1])
        position_now = position_next
    
    return

t = int(sys.stdin.readline())

for _ in range(t):

    n = int(sys.stdin.readline())
    input(n)
    run(points, start)
    
    print(len(lst))
    for position in lst:
        print(position[0], position[1])