import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    orders = list(map(int, sys.stdin.readline().split()))
    total = sum(orders)
    time = 1
    while total <= n:
        time += 1
        total *= 4
    print(time)