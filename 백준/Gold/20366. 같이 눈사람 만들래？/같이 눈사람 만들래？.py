import sys
from itertools import combinations

n = int(sys.stdin.readline())

snows = sorted(list(map(int, sys.stdin.readline().split())))

minimum = float('inf')

for l, r in combinations(range(n), 2):
    compare = snows[l] + snows[r]
    left = 0
    right = n-1
    while left < right:
        total = snows[left] + snows[right]
        if left == l or left == r:
            left += 1
        elif right ==l or right == r:
            right -= 1
        elif total > compare:
            minimum = min(minimum, total-compare)
            right -= 1
        elif total < compare:
            minimum = min(minimum, compare-total)
            left += 1
        elif total == compare:
            minimum = 0
            break
    if minimum == 0:
        break

print(minimum)