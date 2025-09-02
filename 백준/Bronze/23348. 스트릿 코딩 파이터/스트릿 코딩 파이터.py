import sys

A, B, C = map(int, sys.stdin.readline().split())
n = int(sys.stdin.readline())
maximum = 0

for _ in range(n):
    score = 0
    for _ in range(3):
        a, b, c = map(int, sys.stdin.readline().split())
        score += a*A + b*B + c*C
    maximum = max(maximum, score)

print(maximum)