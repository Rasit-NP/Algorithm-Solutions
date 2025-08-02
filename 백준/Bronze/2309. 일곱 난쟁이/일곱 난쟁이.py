import sys

heights = []

for _ in range(9):
    height = int(sys.stdin.readline())
    heights.append(height)

total = sum(heights)

for i in range(len(heights)):
    a = (total-heights[i]-100)
    if a in heights and a != heights[i]:
        fake1 = heights[i]
        fake2 = total-heights[i] - 100
        break

for height in sorted(heights):
    if height == fake1 or height == fake2:
        continue
    else:
        print(height)