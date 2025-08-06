import sys

n = int(sys.stdin.readline())

for i in range(1, n+1):
    ans = ' '*(n-i)
    ans += '*'*i
    print(ans)