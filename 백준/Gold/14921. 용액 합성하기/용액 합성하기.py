import sys

n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))

left = 0
right = n-1
minimum = float('inf')
while right > left:
    sum = lst[left]+lst[right]
    if sum < 0:
        left += 1
    elif sum > 0:
        right -= 1
    elif sum == 0:
        minimum = 0
        break
    if abs(sum) < abs(minimum):
        minimum = sum

print(minimum)