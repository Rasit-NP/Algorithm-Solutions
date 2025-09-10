import sys, math

t = int(sys.stdin.readline())
for _ in range(t):
    a, b = map(int, sys.stdin.readline().split())
    n = math.ceil(a/b)
    print(n**2)