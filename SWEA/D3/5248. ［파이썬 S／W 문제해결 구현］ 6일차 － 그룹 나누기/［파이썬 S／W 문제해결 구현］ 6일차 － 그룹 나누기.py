t = int(input())
for tc in range(1, t+1):

    def find(x):
        root = x
        while root != parents[root]:
            parents[root] = parents[parents[root]]
            root = parents[root]
        parents[x] = root
        return root

    n, m = map(int, input().split())
    parents = [i for i in range(n+1)]
    sets = set(range(1, n+1))
    lst = list(map(int, input().split()))

    for i in range(0, 2*m, 2):
        a, b = lst[i], lst[i+1]
        ra, rb = find(a), find(b)
        ra, rb = min(ra, rb), max(ra, rb)
        if ra != rb:
            parents[rb] = ra
            sets.remove(rb)

    print(f'#{tc}', end=' ')
    print(len(sets))