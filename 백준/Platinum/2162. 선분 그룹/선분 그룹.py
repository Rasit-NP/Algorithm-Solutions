import sys

def input():
    n = int(sys.stdin.readline())
    lines = []
    for _ in range(n):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        lines.append((x1, y1, x2, y2))
    
    return n, lines

def check(line1, line2):
    x1, y1, x2, y2 = line1
    x3, y3, x4, y4 = line2

    if (x1 > max(x3, x4) and x2 > max(x3, x4)) or (y1 > max(y3, y4) and y2 > max(y3, y4)) or (x1 < min(x3, x4) and x2 < min(x3, x4)) or (y1 < min(y3, y4) and y2 < min(y3, y4)):
        return False
    
    def minicheck(position, line):
        x, y = position
        x1, y1, x2, y2 = line
        ans = (y-y1)*(x2-x1)-(x-x1)*(y2-y1)
        if ans > 0:
            return 1
        elif ans == 0:
            return 0
        else:
            return -1

    if minicheck((x1,y1), line2)*minicheck((x2,y2), line2) <=0 and minicheck((x3,y3), line1)*minicheck((x4,y4), line1) <= 0:
        return True
    else:
        return False

n, lines = input()

groups = []

for line in lines:
    idx = []
    for i in range(len(groups)):
        for prev_line in groups[i]:
            if check(line, prev_line):
                idx.append(i)
                break

    if idx:
        sets = set()
        for i in idx[::-1]:
            a = groups.pop(i)
            sets = sets|a
        sets.add(line)
        groups.append(sets)
    else:
        sets = set()
        sets.add(line)
        groups.append(sets)

maximum = 0
for group in groups:
    maximum = max(maximum, len(group))
print(len(groups))
print(maximum)