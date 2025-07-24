import sys
import heapq

n = int(sys.stdin.readline())
points = []

for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    points.append((x,y))

points = sorted(points)

for x, y in points:
    print(x, y)