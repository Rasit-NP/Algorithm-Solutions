import sys

n = int(sys.stdin.readline())

min_x, min_y, max_x, max_y = 11, 11, -11, -11
for _ in range(n):
    a, b, c, d = map(int, sys.stdin.readline().split())
    min_x, min_y, max_x, max_y = min(min_x, a), min(min_y, b), max(max_x, c), max(max_y, d)
    print(2*(max_x-min_x + max_y-min_y))