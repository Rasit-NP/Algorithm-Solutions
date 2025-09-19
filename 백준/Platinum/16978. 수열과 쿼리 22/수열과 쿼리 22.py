import sys, heapq

def init(n):
    global size, tree
    arr = list(map(int, sys.stdin.readline().split()))
    size = 1
    while size < n:
        size <<= 1
    tree = [0] * (2*size)
    for i in range(2*size-1, 0, -1):
        if i >= size+n:
            continue
        elif i >= size:
            tree[i] = arr[i-size]
        else:
            tree[i] = tree[2*i] + tree[2*i+1]
    return

def run(count_update, list_update, list_print):
    global lst_ans
    def update(i, v):
        idx = size + i - 1
        diff = v - tree[idx]
        while idx>=1:
            tree[idx] += diff
            idx //= 2
        return
    def calculate(i, j):
        l, r = size+i-1, size+j-1
        total = 0
        while l<=r:
            if l&1:
                total += tree[l]
                l += 1
            if not r&1:
                total += tree[r]
                r -= 1
            l //= 2
            r //= 2
        return total
    heapq.heapify(list_print)
    lst_ans = []

    for t in range(count_update+1):
        while list_print and list_print[0][0] <= t:
            k, count_print, i, j = heapq.heappop(list_print)
            ans = calculate(i, j)
            lst_ans.append((count_print, ans))
        if t < count_update-1:
            i, v = list_update[t]
            update(i, v)
    return

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    init(n)
    list_update = []
    list_print = []
    count_update = 1
    count_print = 1
    for _ in range(int(sys.stdin.readline())):
        inputs = list(map(int, sys.stdin.readline().split()))
        if inputs[0] == 1:
            i, v = inputs[1], inputs[2]
            list_update.append((i, v))
            count_update += 1
        else:
            k, i, j = inputs[1], inputs[2], inputs[3]
            list_print.append((k, count_print, i, j))
            count_print += 1
    run(count_update, list_update, list_print)

    lst_ans.sort()
    for count, ans in lst_ans:
        print(ans)