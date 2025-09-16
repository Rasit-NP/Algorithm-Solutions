t = int(input())

for tc in range(1, t+1):

    def find(x):
        root = x
        while root != parents[root]:
            parents[root] = parents[parents[root]]
            root = parents[root]
        parents[x] = root
        return root
    
    v, e = map(int, input().split())
    parents = [i for i in range(v+1)]
    edges = []

    for _ in range(e):
        n1, n2, w = map(int, input().split())
        edges.append((w, n1, n2))

    edges.sort()

    count = 0
    total = 0
    for w, a, b in edges:
        ra, rb = find(a), find(b)
        if ra != rb:
            parents[rb] = ra
            count += 1
            total += w
            if count == v:
                break
    ans = total

    print(f'#{tc}', end=' ')
    print(ans)