import sys

n = int(sys.stdin.readline())
lst = [(0, 0), (0, 0), (0, 0)]

for _ in range(n):
    a, b, c = lst
    e, f, g = map(int, sys.stdin.readline().split())
    lst = [(max(a[0], b[0])+e, min(a[1], b[1])+e),
           (max(a[0], b[0], c[0])+f, min(a[1], b[1], c[1])+f),
           (max(b[0], c[0])+g, min(b[1], c[1])+g)
           ]

print(max(lst[0][0], lst[1][0], lst[2][0]), min(lst[0][1], lst[1][1], lst[2][1]))