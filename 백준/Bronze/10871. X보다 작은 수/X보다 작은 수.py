import sys

n, x = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

ans = []

for num in nums:
    if num < x:
        ans.append(num)

sys.stdout.write(' '.join(map(str, ans)))