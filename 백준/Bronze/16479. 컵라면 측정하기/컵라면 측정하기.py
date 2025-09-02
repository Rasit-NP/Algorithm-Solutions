import sys

k = int(sys.stdin.readline())
d1, d2 = map(int, sys.stdin.readline().split())

delta = (d1 - d2)/2

ans = k**2 - delta**2

print(ans)