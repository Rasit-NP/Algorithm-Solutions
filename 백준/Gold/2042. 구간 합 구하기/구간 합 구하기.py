import sys
sys.setrecursionlimit(10**6)

def change(i, v):
    x = size + (i-1)
    diff = v - tree[x]
    while x > 0:
        tree[x] += diff
        x //= 2

def print_sum(i, j):
    
    def total(left, mid, right, node, i, j):
        if i == left and j == right-1:
            return tree[node]
        elif left <= i < mid and mid <= j < right:
            return total(left, (left+mid)//2, mid, node*2, i, mid-1) + total(mid, (mid+right)//2, right, node*2+1, mid, j)
        elif left <= j < mid:
            return total(left, (left+mid)//2, mid, node*2, i, j)
        elif mid <= i < right:
            return total(mid, (mid+right)//2, right, node*2+1, i, j)
    
    ans = total(1, size//2 + 1, size+1, 1, i, j)
    print(ans)
    return

n, m, k = map(int, sys.stdin.readline().split())

size = 1
rank = 0
while size < n:
    rank += 1
    size *= 2

tree = [0] * (2*size)

for i in range(n):
    tree[size+i] = int(sys.stdin.readline())
x = size
x //= 2
while x > 0:
    for i in range(x):
        now = x+i
        tree[now] = tree[2*now] + tree[2*now+1]
    x //= 2

for _ in range(m+k):
    a, b, c = map(int, sys.stdin.readline().split())
    
    if a == 1:
        change(b, c)
    else:
        print_sum(b, c)