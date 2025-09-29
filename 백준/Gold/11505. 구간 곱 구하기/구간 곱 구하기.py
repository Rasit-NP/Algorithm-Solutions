import sys

def init(n):
    global size, mod, tree
    size = 1
    mod = 1000000007

    while size <= n:
        size <<= 1

    tree = [1 for _ in range(size<<1)]
    for i in range(n):
        tree[size+i] = int(sys.stdin.readline())

    for i in range(size-1, 0, -1):
        tree[i] = (tree[2*i]*tree[2*i+1])%mod

def update(i, num):
    idx = size + i - 1
    tree[idx] = num
    idx //= 2
    while idx > 0:
        tree[idx] = (tree[2*idx] * tree[2*idx+1]) % mod
        idx //= 2


def calculate(i, j):
    l = size + i - 1; r = size + j - 1
    total = 1
    while l <= r:
        if l&1:
            total = (total * tree[l]) % mod
            l += 1
        if not r&1:
            total = (total * tree[r]) % mod
            r -= 1
        l //= 2
        r //= 2
    print(total)

if __name__ == '__main__':
    n, m, k = map(int, sys.stdin.readline().split())
    init(n)
    for _ in range(m+k):
        q, a, b = map(int, sys.stdin.readline().split())
        if q == 1:
            update(a, b)
        else:
            calculate(a, b)