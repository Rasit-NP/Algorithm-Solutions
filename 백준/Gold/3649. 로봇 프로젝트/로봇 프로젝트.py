import sys

input = sys.stdin.buffer.readline

while True:
    line = input()
    if not line:
        break
    x = int(line.strip()) * 10000000
    n = int(input().strip())

    legos = [int(input().strip()) for _ in range(n)]
    legos.sort()

    left = 0
    right = n - 1
    ans = ['danger']
    while left < right:
        total = legos[left] + legos[right]
        if total == x:
            ans = ('yes', str(legos[left]), str(legos[right]))
            break
        elif total > x:
            right -= 1
        else:
            left += 1
    
    print(' '.join(ans))