import sys

n = int(sys.stdin.readline())

lst = sorted(list(map(int, sys.stdin.readline().split())))

count = 0
for idx in range(n):
    left = 0
    right = n-1
    while right>left:
        if left == idx:
            left += 1
            continue
        elif right == idx:
            right -= 1
            continue
        target = lst[idx]
        sum = lst[left] + lst[right]
        if target > sum:
            left += 1
        elif target < sum:
            right -= 1
        elif target == sum:
            count += 1
            break
        else:
            break
    
print(count)