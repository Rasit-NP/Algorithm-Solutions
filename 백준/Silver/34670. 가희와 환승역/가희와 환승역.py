import sys

q = int(sys.stdin.readline())

for _ in range(q):
    n = int(sys.stdin.readline())
    cars = list(sys.stdin.readline().rstrip().split())
    last = int(cars[0][-2:])
    check = 1
    for i in range(n):
        if '-' in cars[i]:
            check = 0
            break
        if int(cars[i][-2:]) != last:
            check = 0
            break
    if check and n>1:
        print('YES')
    else:
        print('NO')