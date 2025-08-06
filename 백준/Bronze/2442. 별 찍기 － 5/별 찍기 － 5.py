import sys

n = int(sys.stdin.readline())

for i in range(n):
    ans = ' '*(n-(i+1))
    ans += '*'*(2*i+1)
    print(ans)