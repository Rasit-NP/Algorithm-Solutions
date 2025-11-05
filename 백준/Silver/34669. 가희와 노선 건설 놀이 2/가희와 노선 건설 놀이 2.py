import sys

q = int(sys.stdin.readline())
for _ in range(q):
    c, k = map(int, sys.stdin.readline().split())
    print(c*k, c//k)