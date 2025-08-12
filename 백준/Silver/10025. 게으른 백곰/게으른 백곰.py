import sys

n, k = map(int, sys.stdin.readline().split())

max_bucket = 0
buckets = [0] * (1000003)

for _ in range(n):
    g, x = map(int, sys.stdin.readline().split())
    buckets[x] += g
    max_bucket = max(max_bucket, x)

buckets = buckets[:max_bucket+2]
left = 0
maximum = 0
total = sum(buckets[left:left + 2*k + 1])
if max_bucket > 2*k + 1:
    while left + 2*k + 1 <= max_bucket + 1:
        maximum = max(maximum, total)
        total = total - buckets[left] + buckets[left + 2*k + 1]
        left += 1
else:
    maximum = sum(buckets)

print(maximum)