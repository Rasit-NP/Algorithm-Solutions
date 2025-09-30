import sys
sys.setrecursionlimit(10**6)

def cal(i, j):
    global maximum
    min_local, min_idx = sep(i, j)
    maximum = max(maximum, min_local * (j - i + 1))
    if i<min_idx<j:
        cal(i, min_idx-1)
        cal(min_idx+1, j)
    elif i == j:
        return
    elif i == min_idx:
        cal(min_idx+1, j)
    elif j == min_idx:
        cal(i, min_idx-1)

def sep(i, j):
    l, r = size + i - 1, size + j - 1
    min_local, min_idx = float('inf'), 0
    while l <= r:
        if l&1:
            if tree[l][0] < min_local:
                min_local = tree[l][0]
                min_idx = tree[l][1]
            l += 1
        if not r&1:
            if tree[r][0] < min_local:
                min_local = tree[r][0]
                min_idx = tree[r][1]
            r -= 1
        l //= 2
        r //= 2
    return min_local, min_idx

while True:

    inputs = list(map(int, sys.stdin.readline().split()))
    n = inputs[0]
    if n==0:
        break
    size = 1
    while size < n:
        size *= 2
    tree = [(0, 0) for _ in range(2*size)]
    for i in range(1, n+1):
        idx = size + i - 1
        tree[idx] = (inputs[i], i)
    
    for i in range(size-1, 0, -1):
        if tree[2*i][0] <= tree[2*i+1][0]:
            tree[i] = (tree[2*i][0], tree[2*i][1])
        else:
            tree[i] = (tree[2*i+1][0], tree[2*i+1][1])
    maximum = 0
    cal(1, n)
    print(maximum)