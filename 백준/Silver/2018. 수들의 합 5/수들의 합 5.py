import sys

n = int(sys.stdin.readline())

left, right = 1, 1
total = 1
count = 0
while left <= right <= n:
    if total > n:
        total -= left
        left += 1
    elif total < n:
        right += 1
        total += right
    else:
        count += 1
        right += 1
        total += right

print(count)