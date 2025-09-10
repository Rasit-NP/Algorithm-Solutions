import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
counts = {2:0, 3:0, 5:0, 7:0, 11:0, 13:0, 17:0, 19:0, 23:0}

for num in nums:
    if num == 1:
        continue
    count = {2:0, 3:0, 5:0, 7:0, 11:0, 13:0, 17:0, 19:0, 23:0}
    while True:
        if num in count:
            count[num] += 1
            break
        for key in counts:
            if not num%key:
                count[key] += 1
                num //= key
                break
    for key in counts:
        counts[key] = max(counts[key], count[key])
ans = 2
for key in counts:
    ans *= key ** (counts[key])
print(ans)