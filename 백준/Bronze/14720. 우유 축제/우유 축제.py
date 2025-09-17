import sys

n = int(sys.stdin.readline())

nums = list(map(int, sys.stdin.readline().split()))

find = 0
count = 0
for i in nums:
    if i == find:
        count += 1
        find = (find+1) % 3

print(count)