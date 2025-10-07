import sys

n, k = map(int, sys.stdin.readline().split())
nums = sorted(list(map(int, sys.stdin.readline().split())))
total = 0
for i in range(n):
    total += nums[i] * min(i, k)

print(total)