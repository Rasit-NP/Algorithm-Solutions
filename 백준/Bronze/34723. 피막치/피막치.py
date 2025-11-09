import sys

p, m, c = map(int, sys.stdin.readline().split())
x = int(sys.stdin.readline())

ans = float('inf')
for ip in range(1, p+1):
    for im in range(1, m+1):
        for ic in range(1, c+1):
            ans = min(ans, abs((ip+im)*(im+ic)-x))

print(ans)