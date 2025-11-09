import sys

n = int(sys.stdin.readline())
ans = 0
for _ in range(n):
    b, c, a, i = map(int, sys.stdin.readline().split())
    if (b>=1000 or c>=1600 or a>=1500 or 1<=i<=30):
        ans += 1

print(ans)