import sys
sys.setrecursionlimit(10**6)

def init(n):
    global size, tree

    size = 1
    while size < n:
        size *= 2
    tree = [(float('inf'), 0) for _ in range(2*size)]

    for i in range(n):
        num = int(sys.stdin.readline())
        idx = size + i
        tree[idx] = (num, i)
    
    for idx in range(size-1, 0, -1):
        if tree[idx*2][0] <= tree[idx*2+1][0]:
            tree[idx] = (tree[idx*2][0], tree[idx*2][1])
        elif tree[idx*2][0] > tree[idx*2+1][0]:
            tree[idx] = (tree[idx*2+1][0], tree[idx*2+1][1])

def sep(i, j):
    l, r = size + i, size + j
    minimum, idx = float('inf'), 0
    while l <= r:
        if l&1:
            if tree[l][0] < minimum:
                minimum = tree[l][0]
                idx = tree[l][1]
            l += 1
        if not r&1:
            if tree[r][0] < minimum:
                minimum = tree[r][0]
                idx = tree[r][1]
            r -= 1
        l //= 2
        r //= 2
    return minimum, idx

def run(i, j):
    global maximum
    if i != j:
        now_min, now_idx = sep(i, j)
        maximum = max(maximum, now_min*(j-i + 1))
        if i < now_idx < j:
            run(i, now_idx-1)
            run(now_idx+1, j)
        elif i == now_idx:
            run(now_idx+1, j)
        elif j == now_idx:
            run(i, now_idx-1)
    elif i == j:
        maximum = max(maximum, tree[size + i][0])


if __name__=="__main__":
    n = int(sys.stdin.readline())
    maximum = 0
    init(n)
    run(0, n-1)
    print(maximum)