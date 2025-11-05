import sys

q = int(sys.stdin.readline())
for _ in range(q):
    r, c, k = map(int, sys.stdin.readline().split())
    a, b = c//3, c%3
    if r == 1 or b:
        print(-1)
        continue
    binary = []
    k -= 1
    while (k>0):
        binary.append(k&1)
        k = k >> 1
    lens = len(binary)
    if lens > (a):
        print(-1)
        continue
    while (lens < a):
        binary.append(0)
        lens += 1
    for i in binary[::-1]:
        if i:
            print(322, end='')
        else:
            print(114, end='')
    print()
    for i in binary[::-1]:
        if i:
            print(332, end='')
        else:
            print(144, end='')
    print()