from collections import deque

def bfs(queue):
    a = queue.popleft()
    next = [a-1, a+1, 2*a]
    for i in next:
        if 0<=i<=100000 and visited[i] > visited[a]+1:
            queue.append(i)
            visited[i] = visited[a]+1

n, k = map(int, input().split())
queue = deque([n])
visited = [float('inf')] * 100001
visited[n] = 0

while queue:
    bfs(queue)
    if visited[k] < float('inf'):
        break

print(visited[k])