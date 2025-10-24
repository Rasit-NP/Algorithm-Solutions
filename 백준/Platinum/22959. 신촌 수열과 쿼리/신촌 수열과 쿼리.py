import sys

def init(n):
    global m, size, tree_sum, tree_min
    nums = list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())
    size = 1
    while size <= n:
        size *= 2
    
    tree_sum = [0] * (2*size)
    tree_min = [float('inf') for _ in range(2*size)]
    for i in range(size+n-1, 0, -1):
        if i>=size:
            tree_sum[i] = nums[i-size]
            tree_min[i] = nums[i-size]
        else:
            tree_sum[i] = tree_sum[2*i] + tree_sum[2*i+1]
            tree_min[i] = min(tree_min[2*i], tree_min[2*i+1])

def update(i, j):
    idx = size + i - 1
    tree_sum[idx] = j
    tree_min[idx] = j
    idx //= 2
    while idx > 0:
        tree_sum[idx] = tree_sum[2*idx] + tree_sum[2*idx+1]
        tree_min[idx] = min(tree_min[2*idx], tree_min[2*idx+1])
        idx //= 2

# i를 포함하고, 값이 j보다 큰 구간 찾기
def find(i, j):
    def find_min(a, b):
        minimum = float('inf')
        a_idx = size+a
        b_idx = size+b
        while a_idx <= b_idx:
            if a_idx&1:
                minimum = min(minimum, tree_min[a_idx])
                a_idx += 1
            if not b_idx&1:
                minimum = min(minimum, tree_min[b_idx])
                b_idx -= 1
            a_idx //= 2
            b_idx //= 2
        return minimum
    i -= 1
    left_l = -1
    left_r = i
    while left_r-left_l > 1:
        mid = (left_l + left_r)//2
        val = find_min(mid, i)
        if val >= j:
            left_r = mid
        else:
            left_l = mid
    l = left_r

    right_l = i
    right_r = n
    while right_r-right_l > 1:
        mid = (right_l + right_r)//2
        val = find_min(i, mid)
        if val >= j:
            right_l = mid
        else:
            right_r = mid
    r = right_l

    return l, r
    
def cal(l, r):
    l = size + l
    r = size + r
    ans = 0
    while l <= r:
        if l&1:
            ans += tree_sum[l]
            l += 1
        if not r&1:
            ans += tree_sum[r]
            r -= 1
        l //= 2
        r //= 2
    print(ans)

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    init(n)
    for _ in range(m):
        q, i, j = map(int, sys.stdin.readline().split())
        if q == 1:
            update(i, j)
        elif q == 2:
            l, r = find(i, j)
            cal(l, r)