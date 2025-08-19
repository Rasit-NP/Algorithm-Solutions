import sys

n = int(sys.stdin.readline())

lst = sorted(list(map(int, sys.stdin.readline().split())))
minimum = float('inf')
for i in range(n):
    left = 0
    right = n-1
    base = lst[i]
    while left<right:
        total = base + lst[left] + lst[right]
        if left == i:
            left += 1
            continue
        if right == i:
            right -= 1
            continue
        if total > 0:
            if abs(total) < minimum:
                minimum = abs(total)
                ans = [i, left, right]
            right -= 1
        elif total < 0:
            if abs(total) < minimum:
                minimum = abs(total)
                ans = [i, left, right]
            left += 1
        elif total == 0:
            ans = [i, left, right]
            break
    if minimum == 0:
        break

ans.sort()

print(f'{lst[ans[0]]} {lst[ans[1]]} {lst[ans[2]]}')