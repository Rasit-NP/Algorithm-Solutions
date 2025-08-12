import sys, heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
edges = {}
visited = [float('inf')]*(n+1)
for i in range(1, n+1):
    edges[i] = []
for _ in range(m):
    s, e, c = map(int, sys.stdin.readline().split())
    edges[s].append((c, e))

start, final = map(int, sys.stdin.readline().split())
visited[start] = 0
heap = [(0, start, [start])]

while heap:
    now_cost, position, route = heapq.heappop(heap)
    if position == final:
        heap.clear()
        break
    for cost, next_position in edges[position]:
        if visited[next_position] > visited[position] + cost:
            visited[next_position] = visited[position] + cost
            new_route = route + [next_position]
            heapq.heappush(heap, (visited[next_position], next_position, new_route))

print(now_cost)
print(len(route))
print(' '.join(map(str, route)))