import sys

def init(n):
    global size, nums ,tree
    nums = list(map(int, sys.stdin.readline().split()))
    size = 1
    while size < n:
        size = size << 1
    tree = [(float('inf'),0) for _ in range(size*2)]
    for i in range(n):
        tree[size+i] = (nums[i], i+1)
    for i in range(size-1, 0, -1):
        tree[i] = min(tree[i*2], tree[i*2+1])
    return

def update(i, v):
    idx = size + i - 1
    tree[idx] = (v, i)
    while idx > 1:
        idx //= 2
        tree[idx] = min(tree[idx*2], tree[idx*2+1])
    return

def print_min(i, j):
    l = size + i - 1
    r = size + j - 1
    minimum = (float('inf'),0)
    while l <= r:
        minimum = min(minimum, tree[l], tree[r])
        if l&1:
            l += 1
        if not r&1:
            r -= 1
        l, r = l//2, r//2
    ans = minimum[1]
    sys.stdout.write(f'{ans}\n')

if __name__ == '__main__':

    n = int(sys.stdin.readline())
    init(n)
    m = int(sys.stdin.readline())
    for _ in range(m):
        q, a, b = map(int, sys.stdin.readline().split())
        if q == 1:
            update(a, b)
        else:
            print_min(a, b)