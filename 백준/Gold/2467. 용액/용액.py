import sys

n = int(sys.stdin.readline())

lst = list(map(int, sys.stdin.readline().split()))

left = 0
right = n-1

minimum = float('inf')

while left<right:
    total = lst[left] + lst[right]
    if abs(total) < abs(minimum):
        minimum = total
        min_left = lst[left]
        min_right = lst[right]
    if total > 0:
        right -= 1
    elif total < 0:
        left += 1
    elif total == 0:
        minimum = 0
        break

print(min_left, min_right)