n = int(input())

x = 0;  nx = 1
i = 2
while i<=n:
    tmp = x + nx
    x = nx
    nx = tmp
    i += 1

if (n):
    print(nx)
else:
    print(0)