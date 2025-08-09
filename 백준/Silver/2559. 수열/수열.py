import sys

n, k = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))

if n == k:
    print(sum(lst))
else:
    maximum = -float('inf')

    left, right = 0, k
    now = sum(lst[left:right])
    maximum = -float('inf')

    while True:
        if maximum < now:
            maximum = now
        if right == n:
            break
        now += lst[right] - lst[left]
        right += 1
        left += 1

    print(maximum)