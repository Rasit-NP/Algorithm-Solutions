import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

for i in range(n-2):
    for j in range(n-3, i-1, -1):
        while nums[j] != min(nums[j], nums[j+1], nums[j+2]):
            nums[j], nums[j+1], nums[j+2] = nums[j+2], nums[j], nums[j+1]

ans = 'Yes'
for i in range(n):
    if nums[i] != i+1:
        ans = 'No'
        break

print(ans)