import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())

    a = sorted(list(map(int, sys.stdin.readline().split())))
    b = sorted(list(map(int, sys.stdin.readline().split())))

    total = 0
    count = 0
    b_idx = 0
    for i in range(n):
        while b_idx < m and a[i] > b[b_idx]:
            count += 1
            b_idx += 1
        total += count
    
    print(total)