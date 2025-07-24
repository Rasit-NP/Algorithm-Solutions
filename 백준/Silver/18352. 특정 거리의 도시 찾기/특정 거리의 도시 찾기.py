import sys
from collections import deque

def bfs(queue,k):
    a = queue.popleft()
    if a in dic.keys():
        for i in dic[a]:
            if visited[i] == -1:
                visited[i] = visited[a] + 1
                if visited[i] < k:
                    queue.append(i)
    

n, m, k, x = map(int, sys.stdin.readline().split())
dic = {}
queue = deque([x])
visited = [-1]*(n+1)
visited[x] = 0

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    if a not in dic:    dic[a] = [b]
    else:               dic[a].append(b)

while queue:
    bfs(queue,k)

ans = [i for i in range(1,n+1) if visited[i] == k]
if ans:
    for i in ans:
        sys.stdout.write(f'{i}\n')
else:
    sys.stdout.write('-1\n')