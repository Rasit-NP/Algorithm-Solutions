import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n, m, k = map(int, sys.stdin.readline().split())

    lst = list(map(int, sys.stdin.readline().split()))

    if n == m:
        if sum(lst) < k:
            print(1)
        else:
            print(0)
    else:
        lst *= 2
        left = 0
        right = m
        count = 0
        total = sum(lst[left:right])
        while left < n:
            if total < k:
                count += 1
            total -= lst[left]
            total += lst[right]
            left += 1
            right += 1
        print(count)