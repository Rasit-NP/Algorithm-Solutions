import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    if n&1:
        print(1)
    else:
        print(0)