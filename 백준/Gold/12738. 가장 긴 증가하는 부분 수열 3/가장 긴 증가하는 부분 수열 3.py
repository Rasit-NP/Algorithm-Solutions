import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

tail = []

for i in range(len(nums)):
    if tail:
        if nums[i] > tail[-1]:
            tail.append(nums[i])
        else:
            left, right = -1, len(tail)
            while right-left > 1:
                mid = (right+left)//2
                if tail[mid] >= nums[i]:
                    right = mid
                else:
                    left = mid
            tail[right] = nums[i]
    else:
        tail.append(nums[i])
print(len(tail))