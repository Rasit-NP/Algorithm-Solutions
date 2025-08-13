import sys

n, s = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))


min_length = float('inf')
left = 0
total = 0
for right in range(n):
    total += lst[right]
    while total >= s and right>=left:
        min_length = min(min_length, right-left+1)
        total -= lst[left]
        left += 1
        
if min_length != float('inf'):
    print(min_length)
else:
    print(0)