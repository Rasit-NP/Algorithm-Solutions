import sys

n = int(sys.stdin.readline())

nums = list(map(int, sys.stdin.readline().split()))
lst = [1]
for i in range(1,n):
    lst = lst[:nums[i]] + [i+1] + lst[nums[i]:]

for i in lst[::-1]:
    print(i, end=' ')