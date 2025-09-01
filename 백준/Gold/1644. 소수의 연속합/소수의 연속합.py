import sys

n = int(sys.stdin.readline())
if n > 1:
    nums = [2]

    lst = [True] * (n+1)
    lst[0] = False
    lst[1] = False
    for i in range(2, n+1):
        if lst[i]:
            idx = i*2
            while idx <= n:
                lst[idx] = False
                idx += i

    nums = []
    for i in range(2, n+1):
        if lst[i]:
            nums.append(i)
    length = len(nums)


    left = 0
    right = 0
    total = nums[left]
    count = 0
    while right >= left and right <= length:
        if total < n:
            right += 1
            if right == length:
                break
            total += nums[right]
        elif total > n:
            total -= nums[left]
            left += 1
        elif total == n:
            count += 1
            right += 1
            if right == length:
                break
            total += nums[right]

    print(count)
else:
    print(0)