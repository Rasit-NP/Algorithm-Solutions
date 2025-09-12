import sys, math
from itertools import combinations

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    positions = []
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        positions.append((x, y))
    
    minimum = float('inf')

    for idxes in combinations(range(n), n//2):
        total_x, total_y = 0, 0
        idxes = set(idxes)
        for i in range(n):
            if i in idxes:
                total_x += positions[i][0]
                total_y += positions[i][1]
            else:
                total_x -= positions[i][0]
                total_y -= positions[i][1]
        length = math.sqrt(total_x**2 + total_y**2)
        minimum = min(minimum ,round(length, 7))
    
    print(minimum)