import sys

n, m = map(int, sys.stdin.readline().split())

size = 1
while size < n:
    size *= 2
tree = [float('inf') for _ in range(2*size)]

for i in range(n):
    idx = size + i
    num = int(sys.stdin.readline())
    tree[idx] = num

for i in range(size-1, 0, -1):
    tree[i] = min(tree[2*i], tree[2*i+1])

def cal(a, b, tree):
    l = size + min(a, b) - 1
    r = size + max(a, b) - 1

    minimum = float('inf')
    while l <= r:
        if l%2:
            minimum = min(minimum, tree[l])
            l += 1
        if not r%2:
            minimum = min(minimum, tree[r])
            r -= 1
        l //= 2
        r //= 2
    return minimum

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    print(cal(a, b, tree))