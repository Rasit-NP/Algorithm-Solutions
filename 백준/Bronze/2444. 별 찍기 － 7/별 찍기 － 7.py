import sys

n = int(sys.stdin.readline())

def printing(a):
    ans = ' '*(n-a)
    ans += '*'*(2*a-1)
    print(ans)

for i in range(1, n+1):
    printing(i)
for i in range(n-1, 0, -1):
    printing(i)