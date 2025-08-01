import sys, math

x, y = map(int, sys.stdin.readline().split())

z = (y * 100) // x

if z >= 99:
    print(-1)
else:
    print(math.ceil(((z+1)*x-100*y)/(99-z)))