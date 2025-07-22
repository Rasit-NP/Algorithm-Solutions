import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split())
dic = {}

for i in range(n):
    dic[i+1] = []

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    dic[a].append(b)
    dic[b].append(a)
    dic[a].sort()
    dic[b].sort()

queue = deque([v])
visitedDfs = [False] * (v-1) + [True] + [False] * (n-v)
visitedBfs = [False] * (v-1) + [True] + [False] * (n-v)


listDfs = [v]
listBfs = [v]

def dfs(num):
    for i in range(len(dic[num])):
        if visitedDfs[dic[num][i]-1] == False:
            visitedDfs[dic[num][i]-1] = True
            listDfs.append(dic[num][i])
            dfs(dic[num][i])

def bfs(queue):
    a = queue.popleft()
    for i in range(len(dic[a])):
        if visitedBfs[dic[a][i]-1] == False:
            visitedBfs[dic[a][i]-1] = True
            queue.append(dic[a][i])
            listBfs.append(dic[a][i])


dfs(v)
while queue:
    bfs(queue)
    
print(' '.join(list(map(str, listDfs))))
print(' '.join(list(map(str, listBfs))))