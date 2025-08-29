import sys, heapq

def input():
    n = int(sys.stdin.readline())
    nums = tuple([0] + list(map(int, sys.stdin.readline().split())))

    m = int(sys.stdin.readline())
    edges = [tuple(map(int, sys.stdin.readline().split())) for _ in range(m)]

    return n, m, nums, edges

n, m, nums, edges = input()

heap = []
visited = {}
heapq.heappush(heap, (0, nums))
visited[nums] = 0

ans = -1

while heap:
    dist, lst = heapq.heappop(heap)

    state = True
    for i in range(n):
        if lst[i+1] >= lst[i]:
            continue
        else:
            state = False
            break
    if state:
        ans = dist
        heap.clear()
        break
    for l, r, c in edges:
        new = [None] * (n+1)
        for i in range(n+1):
            if i == r:
                new[i] = lst[l]
            elif i == l:
                new[i] = lst[r]
            else:
                new[i] = lst[i]
        new = tuple(new)
        if new not in visited:
            visited[new] = dist+c
            heapq.heappush(heap, (dist+c, new))
        elif visited[new] > dist+c:
            visited[new] = dist+c
            heapq.heappush(heap, (dist+c, new))

print(ans)